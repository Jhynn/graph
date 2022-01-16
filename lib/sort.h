#ifndef __sort_h
#define __sort_h

#include <stdio.h>

typedef int data;
void show(data array[], unsigned int size);
void insertion(data array[], unsigned int length, int(*comparator)(data, data));

#endif
