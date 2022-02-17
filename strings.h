#ifndef __STRINGS_H__
#define __STRINGS_H__

#include <stddef.h>

void *memrchr(const void* ptr, int ch, size_t pos);
char* strchrnul(const char *s, int c);
void bzero(void * s, size_t n);

#endif
