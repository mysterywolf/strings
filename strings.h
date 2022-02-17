/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-01-12     Meco Man     The first version.
 */

#ifndef __STRINGS_H__
#define __STRINGS_H__

#include <stddef.h>

void *memrchr(const void* ptr, int ch, size_t pos);
char* strchrnul(const char *s, int c);
void bzero(void * s, size_t n);

#endif
