# List of the ChibiOS e200z0 SPC560Bxx startup files.
STARTUPSRC =
          
STARTUPASM = $(CHIBIOS)/os/common/startup/e200/devices/SPC560Bxx/boot.S \
             $(CHIBIOS)/os/common/startup/e200/compilers/GHS/vectors.S \
             $(CHIBIOS)/os/common/startup/e200/compilers/GHS/crt0.S

STARTUPINC = ${CHIBIOS}/os/common/startup/e200/compilers/GHS \
             ${CHIBIOS}/os/common/startup/e200/devices/SPC560Bxx

STARTUPLD  = ${CHIBIOS}/os/common/startup/e200/compilers/GHS/ld
