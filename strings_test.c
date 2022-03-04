/*
 * Copyright (c) 2006-2022, Meco Jianting Man <jiantingman@foxmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-01-12     Meco Man     The first version.
 */

#include <strings.h>
#include <rtthread.h>

static void strings_test(void)
{
    RT_ASSERT(bcmp("hello", "hello", 5) == 0);
    RT_ASSERT(bcmp("hello", "world", 5) != 0);
    RT_ASSERT(bcmp("world", "hello", 5) != 0);

    char buffer[6];
    bcopy("hello", buffer, 5);
    RT_ASSERT(bcmp("hello", buffer, 5) == 0);
    RT_ASSERT(bcmp(buffer, "hello", 5) == 0);
    RT_ASSERT(bcmp("world", buffer, 5) != 0);
    RT_ASSERT(bcmp(buffer, "world", 5) != 0);
    bcopy("world", buffer, 5);
    RT_ASSERT(bcmp("hello", buffer, 5) != 0);
    RT_ASSERT(bcmp(buffer, "hello", 5) != 0);
    RT_ASSERT(bcmp("world", buffer, 5) == 0);
    RT_ASSERT(bcmp(buffer, "world", 5) == 0);

    bzero(buffer, 5);
    RT_ASSERT(bcmp(buffer, "\0\0\0\0\0", 5) == 0);
    RT_ASSERT(bcmp("\0\0\0\0\0", buffer, 5) == 0);
    RT_ASSERT(bcmp("hello", buffer, 5) != 0);
    RT_ASSERT(bcmp(buffer, "hello", 5) != 0);

    explicit_bzero(buffer, 5);
    RT_ASSERT(bcmp(buffer, "\0\0\0\0\0", 5) == 0);
    RT_ASSERT(bcmp("\0\0\0\0\0", buffer, 5) == 0);
    RT_ASSERT(bcmp("hello", buffer, 5) != 0);
    RT_ASSERT(bcmp(buffer, "hello", 5) != 0);

    char hello[] = "hello";
    char world[] = "world";
    RT_ASSERT(index(hello, 'e') == hello + 1);
    RT_ASSERT(rindex(hello, 'e') == hello + 1);
    RT_ASSERT(index(hello, 'l') == hello + 2);
    RT_ASSERT(rindex(hello, 'l') == hello + 3);
    RT_ASSERT(index(hello, 'w') == NULL);
    RT_ASSERT(rindex(hello, 'w') == NULL);

    RT_ASSERT(index(world, 'e') == NULL);
    RT_ASSERT(rindex(world, 'e') == NULL);
    RT_ASSERT(index(world, 'l') == world + 3);
    RT_ASSERT(rindex(world, 'l') == world + 3);
    RT_ASSERT(index(world, 'w') == world);
    RT_ASSERT(rindex(world, 'w') == world);

    RT_ASSERT(ffs(0) == 0);
    RT_ASSERT(ffs(1) == 1);
    RT_ASSERT(ffs(2) == 2);
    RT_ASSERT(ffs(3) == 1);
    RT_ASSERT(ffs(4) == 3);
    RT_ASSERT(ffs(5) == 1);

    RT_ASSERT(ffsl(0) == 0);
    RT_ASSERT(ffsl(1) == 1);
    RT_ASSERT(ffsl(2) == 2);
    RT_ASSERT(ffsl(3) == 1);
    RT_ASSERT(ffsl(4) == 3);
    RT_ASSERT(ffsl(5) == 1);

    RT_ASSERT(ffsll(0) == 0);
    RT_ASSERT(ffsll(1) == 1);
    RT_ASSERT(ffsll(2) == 2);
    RT_ASSERT(ffsll(3) == 1);
    RT_ASSERT(ffsll(4) == 3);
    RT_ASSERT(ffsll(5) == 1);

    RT_ASSERT(strcasecmp("hello", "hello") == 0);
    RT_ASSERT(strcasecmp("HELLO", "hello") == 0);
    RT_ASSERT(strcasecmp("HELLO", "world") != 0);
    RT_ASSERT(strcasecmp("hello", "hello2") != 0);
    RT_ASSERT(strcasecmp("hello2", "hello") != 0);
    RT_ASSERT(strcasecmp("hello2", "hello1") != 0);

    RT_ASSERT(strncasecmp("hello", "hello", 5) == 0);
    RT_ASSERT(strncasecmp("HELLO", "hello", 5) == 0);
    RT_ASSERT(strncasecmp("HELLO", "world", 5) != 0);
    RT_ASSERT(strncasecmp("hello", "hello2", 5) == 0);
    RT_ASSERT(strncasecmp("hello2", "hello", 5) == 0);
    RT_ASSERT(strncasecmp("hello2", "hello1", 6) != 0);
    RT_ASSERT(strncasecmp("hello2", "hello12", 6) != 0);
}
MSH_CMD_EXPORT(strings_test, test strings);
