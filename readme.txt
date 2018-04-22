*****************************************************************************
*** Files Organization                                                    ***
*****************************************************************************

--{root}                  - ChibiOS directory.
  +--readme.txt           - This file.
  +--documentation.html   - Shortcut to the web documentation page.
  +--license.txt          - GPL license text.
  +--demos/               - Demo projects, one directory per platform.
  +--docs/                - Documentation.
  |  +--common/           - Documentation common build resources.
  |  +--hal/              - Builders for HAL.
  |  |  +--Doxyfile_*     - Doxygen project files (required for rebuild).
  |  |  +--html/          - Local HTML documentation (after rebuild).
  |  |  +--reports/       - Test reports.
  |  |  +--rsc/           - Documentation resource files (required for rebuild).
  |  |  +--src/           - Documentation source files (required for rebuild).
  |  |  +--Doxyfile_*     - Doxygen project files (required for rebuild).
  |  |  +--index.html     - Local documentation access (after rebuild).
  |  +--nil/              - Builders for NIL.
  |  |  +--Doxyfile_*     - Doxygen project files (required for rebuild).
  |  |  +--html/          - Local HTML documentation (after rebuild).
  |  |  +--reports/       - Test reports.
  |  |  +--rsc/           - Documentation resource files (required for rebuild).
  |  |  +--src/           - Documentation source files (required for rebuild).
  |  |  +--Doxyfile_*     - Doxygen project files (required for rebuild).
  |  |  +--index.html     - Local documentation access (after rebuild).
  |  +--rt/               - Builders for RT.
  |  |  +--html/          - Local HTML documentation (after rebuild).
  |  |  +--reports/       - Test reports.
  |  |  +--rsc/           - Documentation resource files (required for rebuild).
  |  |  +--src/           - Documentation source files (required for rebuild).
  |  |  +--Doxyfile_*     - Doxygen project files (required for rebuild).
  |  |  +--index.html     - Local documentation access (after rebuild).
  +--ext/                 - External libraries, not part of ChibiOS/RT.
  +--os/                  - ChibiOS components.
  |  +--common/           - Shared OS modules.
  |  |  +--abstractions/  - API emulator wrappers.
  |  |  |  +--cmsis_os/   - CMSIS OS emulation layer for RT (ARMCMx port only).
  |  |  |  +--nasa_osal/  - NASA Operating System Abstraction Layer for RT.
  |  |  +--ext/           - Vendor files used by the OS.
  |  |  +--ports/         - RTOS ports usable by both RT and NIL.
  |  |  +--startup/       - Startup support for all compilers and platforms.
  |  +--ex/               - EX component.
  |  |  +--dox/           - EX documentation resources.
  |  |  +--Micron/        - EX complex drivers for Micron devices.
  |  |  +--ST/            - EX complex drivers for STMicroelectronics devices.
  |  |  +--subsystems/    - EX subsystems.
  |  |  |  +--mfs/        - EX Managed Flash Storage module.
  |  +--hal/              - HAL component.
  |  |  +--boards/        - HAL board support files.
  |  |  +--dox/           - HAL documentation resources.
  |  |  +--include/       - HAL high level headers.
  |  |  +--lib/           - HAL libraries.
  |  |  |  +--complex/    - HAL collection of complex drivers.
  |  |  |  |  +--mfs/     - HAL managed flash storage driver.
  |  |  |  +--fallback/   - HAL fall back software drivers.
  |  |  |  +--peripherals/- HAL peripherals interfaces.
  |  |  |  +--streams/    - HAL streams.
  |  |  +--osal/          - HAL OSAL implementations.
  |  |  |  +--lib/        - HAL OSAL common modules.
  |  |  +--src/           - HAL high level source.
  |  |  +--ports/         - HAL ports.
  |  |  +--templates/     - HAL driver template files.
  |  |     +--osal/       - HAL OSAL templates.
  |  +--lib/              - RTOS modules usable by both RT and NIL (OSLIB).
  |  |  +--include/       - OSLIB high level headers.
  |  |  +--src/           - OSLIB high level source.
  |  |  +--templates/     - OSLIB configuration template files.
  |  +--nil/              - NIL RTOS component.
  |  |  +--dox/           - NIL documentation resources.
  |  |  +--include/       - NIL high level headers.
  |  |  +--src/           - NIL high level source.
  |  |  +--templates/     - NIL configuration template files.
  |  +--rt/               - RT RTOS component.
  |  |  +--dox/           - RT documentation resources.
  |  |  +--include/       - RT high level headers.
  |  |  +--src/           - RT high level source.
  |  |  +--templates/     - RT configuration template files.
  |  +--various/          - Various portable support files.
  +--test/                - Kernel test suite source code.
  |  +--lib/              - Portable test engine.
  |  +--hal/              - HAL test suites.
  |  |  +--testbuild/     - HAL build test and MISRA check.
  |  +--nil/              - NIL test suites.
  |  |  +--testbuild/     - NIL build test and MISRA check.
  |  +--rt/               - RT test suites.
  |  |  +--testbuild/     - RT build test and MISRA check.
  |  |  +--coverage/      - RT code coverage project.
  +--testhal/             - HAL integration test demos.

*****************************************************************************
*** Releases and Change Log                                               ***
*****************************************************************************

*** Next ***
- NEW: RT C++ wrapper reworked, now it is mostly inline code, added some new
       wrappers and methods. Added wrappers for more API functions. BaseThreads
       are no more descendants of ThreadReference. Some classes turned in
       namespaces.
- NEW: Updated STM32L4xx headers to version 1.11.0.
- NEW: Added HAL support for STM32L443.
- NEW: Added support for LDM303AGR 6 axis Accelerometer\Magnetometer MEMS.
- NEW: Added support for LSM6DSL 6 axis Accelerometer\Gyroscope MEMS.
- NEW: Added support for LPS22HB 2 axis Barometer\Thermometer MEMS.
- NEW: Separated OSLIB from RT and NIL, now it is a separate "product" with
       its own version, configuration file and licensing. The library will
       grow to include more functionalities.
       RT and NIL will contain only the core functionalities, everything else
       is shared library code.
- EX:  Updated HTS221 to 1.1.0 (backported to 18.2.1).
- EX:  Updated L3GD20 to 1.1.0 (backported to 18.2.1).
- EX:  Updated LIS3DSH to 1.1.0 (backported to 18.2.1).
- EX:  Updated LIS3MDL to 1.1.0 (backported to 18.2.1).
- EX:  Updated LIS302DL to 1.1.0 (backported to 18.2.1).
- EX:  Updated LPS25H to 1.1.0 (backported to 18.2.1).
- EX:  Updated LSM303DLHC to 1.1.0 (backported to 18.2.1).
- HAL: Fixed STM32 USBv1 driver does not reset data toggling bits on endpoint
       initialization (bug #939)(backported to 18.2.1 and 17.6.5).
- HAL: Fixed incorrect behavior of USB driver on SET CONFIGURATION (bug #938)
       (backported to 18.2.1 and 17.6.5).
- HAL: Fixed macro expansion problem in SPI high level driver (bug #937)
       (backported to 18.2.1).
- HAL: Fixed missing CAN2 macros from STM32L4xx stm32_rcc.h file (bug #936)
       (backported to 18.2.1).
- OTH: Fixed inclusion order problem in STM32L4 cmparams.h file (bug #935)
       (backported to 18.2.1 and 17.6.5).
- HAL: Fixed problem clearing UIF timer flag in STM32 PWM driver (bug #934)
       (backported to 18.2.1 and 17.6.5).
- HAL: Fixed USB Serial driver problem with zero-size OUT transactions
       (bug #933)(backported to 18.2.1 and 17.6.5).
- HAL: Fixed race condition in STM32 QSPI driver (bug #932)(backported to
       18.2.1 and 17.6.5).
- HAL: Fixed function mfsReadRecord() causes memory corruption because a
       buffer overflow (bug #931)(backported to 18.2.1).
- HAL: Fixed silence GCC 7.3.0 warning (bug #930)(backported to 18.2.1
       and 17.6.5).
- HAL: Fixed invalid SAI1 clock selection on STM32F7xx (bug #929)(backported
       to 18.2.1 and 17.6.4).
- HAL: Fixed invalid clock checks for SDMMC1 and SDMMC2 on STM32F7xx
       (bug #928)(backported to 18.2.1).
- HAL: Fixed useless writes in read-only CFGR_SWS field on all STM32Fxx
       (bug #927)(backported to 18.2.1 and 17.6.4).
- HAL: Fixed typo in hal_pal.h (bug #926)(backported to 18.2.1).
- HAL: Fixed I2C address not accepted (bug #923)(backported to 18.2.1
       and 17.6.4).
- HAL: Fixed problem with HSI48 on STM32L4xx (bug #922)(backported to 18.2.1).
- HAL: Fixed invalid implementation of palWaitPadTimeoutS() and
       palWaitLineTimeoutS() APIs (bug #921)(backported to 18.2.1).
- HAL: Fixed wrong DMA settings for STM32F76x I2C3 and I2C4 (bug #920)
       (backported to 18.2.1 and 17.6.4).
- HAL: Fixed wrong flash waiting state for STM32F7xx (bug #918)
       (backported to 18.2.1 and 17.6.4).
