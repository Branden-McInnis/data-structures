#ifndef __QUEUE_HEADER
#define __QUEUE_HEADER
#include <stdbool.h>

typedef struct _Node{
    
	void* data;
	
	struct _Node* next;
	
	struct _Node* prev;
	
} Node;

typedef struct _Stack{
    
	Node* first;
	
	int size;
	
	int itemSize;
	
	char* type;	
	
}Stack;


Stack* stack_initialize(int, char*);

bool stack_push(Stack*, void*);

void* stack_pop(Stack*);

void* stack_peek(Stack*);

int stack_size( Stack*);

bool stack_contains( Stack*, void*);

bool stack_destroy( Stack*);


#endif


