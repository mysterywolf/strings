/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-01-12     Meco Man     The first version.
 */

#include "strings.h"

/**
 * @brief The memchr() function scans the initial n bytes of the memory area pointed to
 *        by s for the first instance of c. Both c and the bytes of the memory area
 *        pointed to by s are interpreted as unsigned char.
 *
 * @note  This function is GNU extension, available since glibc 2.1.91.
 */
void* memrchr(const void* ptr, int ch, size_t pos)
{
    char *end = (char *)ptr+pos-1;
    while (end != ptr)
    {
        if (*end == ch)
            return end;
        end--;
    }
    return (*end == ch)?(end):(NULL);
}

char* strchrnul(const char *s, int c)
{
    while (*s != '\0' && *s != c)
        s++;
    return (char*)s;
}

/**
 * @brief erases the data in the n bytes of the memory starting at the
 *        location pointed to by s, by writing zeros (bytes containing '\0') to that area.
 *        
 * @note  The bzero() function is deprecated (marked as LEGACY in POSIX. 1-2001).
 */
void bzero(void * s, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = '\0';
        i++;
    }
}
