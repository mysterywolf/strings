/*
 * Copyright (c) 2022, Meco Jianting Man <jiantingman@foxmail.com>
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

void bzero(void * s, size_t n);
void bcopy(const void * src, void * dest, size_t n);
int bcmp(const void * s1, const void * s2, size_t n);
void explicit_bzero(void * s, size_t n);
char *index(const char * s, int c);
char *rindex(const char * s, int c);
int ffs(int i);
int ffsl(long i);
int ffsll(long long i);
void *memrchr(const void* ptr, int ch, size_t pos);
size_t strnlen(const char *s, size_t maxlen);
char* strchrnul(const char *s, int c);
int strcasecmp(const char * s1, const char * s2);
int strncasecmp(const char * s1, const char * s2, size_t n);
char *strdup(const char *s);
char *strndup(const char *s, size_t size);
char *strtok_r(char *str, const char *delim, char **saveptr);

#endif
