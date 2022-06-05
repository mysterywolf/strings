/*
 * Copyright (c) 2006-2022, Meco Jianting Man <jiantingman@foxmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-01-12     Meco Man     The first version.
 */

#include "strings.h"
#include <ctype.h>
#include <rtthread.h>
#include <string.h>

/**
 * @brief erases the data in the n bytes of the memory starting at the
 *        location pointed to by s, by writing zeros (bytes containing '\0') to that area.
 *
 * @note  The bzero() function is deprecated (marked as LEGACY in POSIX. 1-2001).
 */
void bzero(void* s, size_t n)
{
    rt_memset(s, 0, n);
}

void bcopy(const void* src, void* dest, size_t n)
{
    rt_memcpy(dest, src, n);
}

int bcmp(const void* s1, const void* s2, size_t n)
{
    return rt_memcmp(s1, s2, n);
}

void explicit_bzero(void* s, size_t n)
{
    volatile char* vs = (volatile char*)s;
    while (n) {
        *vs++ = 0;
        n--;
    }
}

char* index(const char* s, int c)
{
    return strchr(s, c);
}

char* rindex(const char* s, int c)
{
    return strrchr(s, c);
}

int ffs(int i)
{
    int bit;

    if (0 == i)
        return 0;

    for (bit = 1; !(i & 1); ++bit)
        i >>= 1;
    return bit;
}

int ffsl(long i)
{
    int bit;

    if (0 == i)
        return 0;

    for (bit = 1; !(i & 1); ++bit)
        i >>= 1;
    return bit;
}

int ffsll(long long i)
{
    int bit;

    if (0 == i)
        return 0;

    for (bit = 1; !(i & 1); ++bit)
        i >>= 1;
    return bit;
}

/**
 * @brief The memchr() function scans the initial n bytes of the memory area pointed to
 *        by s for the first instance of c. Both c and the bytes of the memory area
 *        pointed to by s are interpreted as unsigned char.
 *
 * @note  This function is GNU extension, available since glibc 2.1.91.
 */
void* memrchr(const void* ptr, int ch, size_t pos)
{
    char* end = (char*)ptr + pos - 1;
    while (end != ptr) {
        if (*end == ch)
            return end;
        end--;
    }
    return (*end == ch) ? (end) : (NULL);
}

size_t strnlen(const char *s, size_t maxlen)
{
    const char *sc;
    for (sc = s; maxlen != 0 && *sc != '\0'; maxlen--, ++sc);
    return sc - s;
}

char* strchrnul(const char* s, int c)
{
    while (*s != '\0' && *s != c)
        s++;
    return (char*)s;
}

int strcasecmp(const char* s1, const char* s2)
{
    const unsigned char* u1 = (const unsigned char*)s1;
    const unsigned char* u2 = (const unsigned char*)s2;
    int result;

    while ((result = tolower(*u1) - tolower(*u2)) == 0 && *u1 != 0) {
        u1++;
        u2++;
    }

    return result;
}

int strncasecmp(const char* s1, const char* s2, size_t n)
{
    const unsigned char* u1 = (const unsigned char*)s1;
    const unsigned char* u2 = (const unsigned char*)s2;
    int result;

    for (; n != 0; n--) {
        result = tolower(*u1) - tolower(*u2);
        if (result)
            return result;
        if (*u1 == 0)
            return 0;
        u1++;
        u2++;
    }
    return 0;
}
