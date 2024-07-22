include $(JZ2440_ROOT_PATH)/Makefile.build

OBJS := crt0.o nand.o main.o

all: $(OBJS)
	$(Q)$(CC) $(LDFLAGS) -T nand.lds $(OBJS) -o $(OUTPUT).elf
	$(Q)$(OBJDUMP) -D -m arm $(OUTPUT).elf > $(OUTPUT).dump
	$(Q)$(OBJCOPY) -O binary -S $(OUTPUT).elf $(OUTPUT).bin
	$(Q)echo "\e[32m>>> compiled $(OUTPUT) success.\e[0m"

clean:
	rm -f *.o *.bin *.elf *.dump *.map
