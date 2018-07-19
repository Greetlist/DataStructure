#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
	size_t value;
	char key;
};

struct Heap {
	struct Element* head;
	int size;
	int tail;
};

extern void heapJustify(struct Heap* heap);

extern struct Element extractMin(struct Heap* heap);

extern void exchangeElement(struct Element* first, struct Element* second);

extern void insertElement(struct Element* element, struct Heap* heap);

extern struct Heap* allocHeap(size_t size);

extern void printHeapArray(struct Heap* heap);

#endif
