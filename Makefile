export Q = @
export JZ2440_ROOT_PATH = $(shell pwd)

export PATH := $(JZ2440_ROOT_PATH)/cross_compiler/gcc-arm-none-eabi-6-2017-q2-update/bin:$(PATH)
export CROSS_COMPILE = arm-none-eabi-

export CC=$(CROSS_COMPILE)gcc
export LD=$(CROSS_COMPILE)ld
export AR=$(CROSS_COMPILE)ar
export OBJCOPY=$(CROSS_COMPILE)objcopy
export OBJDUMP=$(CROSS_COMPILE)objdump
export GDB=$(CROSS_COMPILE)gdb

export CFLAGS = -Wall -O2 -I$(JZ2440_ROOT_PATH)/include
export LDFLAGS = 

exclude_dirs := cross_compiler include tools
SUBDIR:=$(sort $(filter-out $(exclude_dirs),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d)))))

all: 
ifneq ($(T),)
	$(Q)make -C $(JZ2440_ROOT_PATH)/$(T)
else
	$(Q)for T in $(SUBDIR); do \
		make -C $(JZ2440_ROOT_PATH)/$$T; \
	done
endif

openocd:
	$(Q)openocd -f configs/openocd_jz2440v3.cfg

gdb:
	$(Q)$(GDB)

clean: 
ifneq ($(T),)
	$(Q)make clean -C $(JZ2440_ROOT_PATH)/$(T)
else
	$(Q)for T in $(SUBDIR); do \
		make clean -C $(JZ2440_ROOT_PATH)/$$T; \
	done
endif
