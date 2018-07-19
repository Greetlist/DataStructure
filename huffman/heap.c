#include "heap.h"

extern void heapJustify(struct Heap* heap) {
	int startIndex = (heap->tail >> 1) - 1;
	for (; startIndex >= 0; --startIndex) {
		struct Element* left = heap->head + (startIndex << 1) + 1;
		struct Element* right = (startIndex << 1) + 2 >= heap->tail ? NULL : heap->head + (startIndex << 1) + 2;
		struct Element* min = heap->head + startIndex;
		if (left != NULL && right != NULL) {
			min = min->key > left->key ? left : min;
			min = min->key > right->key ? right : min;
		} else if (left != NULL) {
			min = min->key > left->key ? left : min;
		}
		exchangeElement(heap->head + startIndex, min);
	}
}

extern struct Element extractMin(struct Heap* heap) {
	struct Element returnValue;
	returnValue.key = heap->head->key;
	returnValue.value = heap->head->value;
	memmove(heap->head, heap->head + 1, sizeof(struct Element) * (--heap->tail));
	memset(heap->head + heap->tail, 0, sizeof(struct Element));
	heapJustify(heap);
	return returnValue;
}

extern void exchangeElement(struct Element* first, struct Element* second) {
	if (first == second) {
		return ;
	}
	struct Element current;
	current.key = first->key;
	current.value = first->value;
	first->key = second->key;
	first->value = second->value;
	second->key = current.key;
	second->value = second->value;
}

extern void insertElement(struct Element* element, struct Heap* heap) {
	if (heap->size - 1 == heap->tail) {
		perror("Heap Is Full");
		return ;
	}
	memcpy(heap->head + heap->tail, element, sizeof(struct Element));
	heap->tail++;
	heapJustify(heap);
}

extern struct Heap* allocHeap(size_t size) {
	size_t block = sizeof(struct Element) * size;
	struct Heap* returnPtr = malloc(sizeof(struct Heap));
	returnPtr->head = malloc(block);
	memset(returnPtr->head, 0, block);
	returnPtr->size = size;
	returnPtr->tail = 0;
	if (returnPtr == NULL || returnPtr->head == NULL) {
		perror("Malloc Failed");
		return NULL;
	}
	return returnPtr;
}

extern void printHeapArray(struct Heap* heap) {
	for (int i = 0; i < heap->tail; ++i) {
		printf("The Key is : %c, Value is : %ld.\n", (heap->head + i)->key, (heap->head + i)->value);
	}
	printf("\n");
}
