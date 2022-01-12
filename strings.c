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
void* memrchr(const void *s, int c, size_t n)
{
    register const char* t=s;
    register const char* last=0;
    int i;

    t = t + n;
    for (i=n; i; --i)
    {
        if (*t==c)
        {
            last=t;
            break;
        }
        t--;
    }
    return (void*)last; /* man, what an utterly b0rken prototype */
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
