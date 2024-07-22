OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 64M
    RAM (rwx)   : ORIGIN = 0x30000000, LENGTH = 64M
}

SECTIONS
{
    .boot : 
    {
        *(.init)
        nand.o
        . = 0x1000;
    } > FLASH

    .text :
    {
        *(.text)
        *(.gnu.linkonce.t*)
    } > RAM AT > FLASH
}