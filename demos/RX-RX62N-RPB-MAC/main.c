/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "lwipthread.h"
#include "web/web.h"

static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

  while (TRUE) {
    palClearPad(GPIO10, PORTA_LED0);
    chThdSleepMilliseconds(50);
    palClearPad(GPIO10, PORTA_LED1);
    chThdSleepMilliseconds(50);
    palClearPad(GPIO10, PORTA_LED2);
    palSetPad(GPIO10, PORTA_LED0);
    chThdSleepMilliseconds(50);
    palSetPad(GPIO10, PORTA_LED1);
    chThdSleepMilliseconds(50);
    palSetPad(GPIO10, PORTA_LED2);
    chThdSleepMilliseconds(50);
    chThdSleepMilliseconds(400);
  }
  return 0;
}

/*===========================================================================*/
/* Main and generic code.                                                    */
/*===========================================================================*/

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the serial driver 1 using the driver default configuration.
   */
  sdStart(&SD1, NULL);

  /*
   * Starts the LED blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Creates the LWIP threads (it changes priority internally).
   */
  chThdCreateStatic(wa_lwip_thread, LWIP_THREAD_STACK_SIZE, NORMALPRIO + 1,
                    lwip_thread, NULL);

/*
   * Creates the HTTP thread (it changes priority internally).
   */
  chThdCreateStatic(wa_http_server, sizeof(wa_http_server), NORMALPRIO + 1,
                    http_server, NULL);

  chprintf((BaseSequentialStream *)&SD1, "\r\nRX62N Ethernet demo.\r\n");

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and listen for events.
   */
  while (TRUE) {

    chThdSleepMilliseconds(1000);
  }
  return 0;
}
