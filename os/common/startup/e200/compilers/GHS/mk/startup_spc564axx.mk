# List of the ChibiOS e200z4 SPC564Axx startup files.
STARTUPSRC =
          
STARTUPASM = $(CHIBIOS)/os/common/startup/e200/devices/SPC564Axx/boot.S \
             $(CHIBIOS)/os/common/startup/e200/compilers/GHS/vectors.S \
             $(CHIBIOS)/os/common/startup/e200/compilers/GHS/crt0.S

STARTUPINC = ${CHIBIOS}/os/common/startup/e200/compilers/GHS \
             ${CHIBIOS}/os/common/startup/e200/devices/SPC564Axx

STARTUPLD  = ${CHIBIOS}/os/common/startup/e200/compilers/GHS/ld
