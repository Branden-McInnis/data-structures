#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

Heap* heap_initialize(int size, char* name, int (*compare)(void*, void*), void (*print)(void*)){

    if(size == 0 || name == NULL || compare == NULL || print == NULL){
    
        return NULL;

    }

    Heap* heap = malloc(sizeof(*heap));

    heap->compare = compare;
    heap->print = print;
    heap->list = alist_initialize(10, size, name);

    return heap;

}

bool heap_insert(Heap* heap, void* element){
    
    if(heap == NULL || element == NULL){

        return false;

    }

    int sizePtr = heap->list->size;

    bool added = alist_add(heap->list,element);

    _heapify_up(heap, sizePtr - 1);

    return added;

}

void* heap_remove(Heap* heap){

    if(heap == NULL){

        return NULL;

    }

    int sizePtr = heap->list->size;
    
    alist_swap(heap->list, 0, sizePtr - 1);
    
    void* removePtr =  alist_remove(heap->list, sizePtr - 1);
    _heapify(heap, 0);

    return removePtr;

}

void* heap_peek(Heap* heap){

    if(heap == NULL){
 
         return NULL;

    }

    void* peekPtr = alist_get(heap->list, 0); 

    return peekPtr;

}

int heap_size(Heap* heap){

    int sizePtr = heap->list->size;

    return sizePtr;

}

bool heap_contains(Heap* heap, void* element){


    if(heap == NULL || element == NULL){

        return false;

    }


    int indexPtr = alist_index_of(heap->list, element);
   
    if(indexPtr == -1){

        return false;
    
    }

    void*  elementPtr = alist_get(heap->list, indexPtr);
   
    if(heap->compare(element, elementPtr) == 0 && elementPtr != NULL){

        return true;

    }

    if(heap->compare(element, elementPtr) != 0 && elementPtr != NULL){

        return false;

    }
    return false;



}

bool _heapify(Heap* heap, int index){
    
   int sizePtr = heap->list->size;
   int left =( 2 * index) + 1;
   int right = (2 * index) + 2;
   int top = index;

   if(left < sizePtr && heap->compare(alist_get(heap->list, left), alist_get(heap->list, index)) > 0){

     top = left;

   }

   if(right < sizePtr && heap->compare(alist_get(heap->list, right), alist_get(heap->list, top)) > 0){

       top = right;


   }

   if(top != index){
        
       alist_swap(heap->list, top, index); 

       return  _heapify(heap, top);
 
   }

   return true;

}

bool _heapify_up(Heap* heap, int index) {

    int index_parent = (index - 1) / 2;

    if(index_parent >= 0 && heap->compare(alist_get(heap->list, index), alist_get(heap->list, index_parent)) > 0){

         alist_swap(heap->list, index, index_parent);
            

         index = index_parent;
    
    
         return  _heapify_up(heap, index);
    }

    return true;

}
