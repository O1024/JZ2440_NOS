/**
 * @file init.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "s3c24x0.h"

void disable_watch_dog(void)
{
    WTCON = 0;

    return;
}
