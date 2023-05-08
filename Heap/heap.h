#ifndef __HEAP_HEADER
#define __HEAP_HEADER
#include "array_list.h"
#include "stdbool.h"

typedef struct _Heap{

    ArrayList* list;
    int (*compare)(void*,void*);
    void (*print)(void*);

}Heap;

Heap* heap_initialize(int, char*, int (*)(void*, void*), void (*)(void*));

bool heap_insert(Heap*, void*);

void* heap_remove(Heap*);

void* heap_peek(Heap*);

int heap_size(Heap*);

bool heap_contains(Heap*, void*);

bool _heapify(Heap*, int);

bool _heapify_up(Heap*, int);

#endif






