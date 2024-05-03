/**
 * @file crt0.S
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

.text
.global _start
_start:
    ldr sp, =4096
    bl  disable_watch_dog
    bl  main

halt_loop:
    b halt_loop
