target extended-remote localhost:3333
set confirm off
printf "------------------------------------------\n"
printf ">>> echo \"monitor help_2440\" to get help message. \n"
printf "------------------------------------------\n"

define gdb_help
    monitor help_2440
end

define gdb_flash_bin
   monitor flash_bin $arg0/$arg0.bin
   printf "Write $arg0 to Nand Flash Done!\n"
end

define gdb_debug_flash_bin
    file $arg0/$arg0.elf
    load
    b _start
    c
end

define gdb_show_interrupt_regs
    printf "SRCPND \t\t"
    x 0x4A000000
    printf "INTMOD \t\t"
    x 0x4A000004
    printf "INTMSK \t\t"
    x 0x4A000008
    printf "PRIORITY \t"
    x 0x4A00000C
    printf "INTPND \t\t"
    x 0x4A000010
    printf "INTOFFSET \t"
    x 0x4A000014
    printf "SUBSRCPND \t"
    x 0x4A000018
    printf "INTSUBMSK \t"
    x 0x4A00001C
end

define gdb_show_timer_regs
    printf "TCFG0 \t"
    x 0x51000000
    printf "TCFG1 \t"
    x 0x51000004
    printf "TCON \t"
    x 0x51000008
    printf "TCNTB0 \t"
    x 0x5100000C
    printf "TCMPB0 \t"
    x 0x51000010
    printf "TCNTO0 \t"
    x 0x51000014
end

define gdb_show_gpio_regs
    printf "GPFCON \t"
    x 0x56000050
    printf "GPFDAT \t"
    x 0x56000054
    printf "GPFUP \t"
    x 0x56000058
end
