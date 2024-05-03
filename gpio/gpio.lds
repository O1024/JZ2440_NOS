/**
 * @file gpio.lds
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS { 
  firtst    0x00000000 : { crt0.o init.o main.o }
}
