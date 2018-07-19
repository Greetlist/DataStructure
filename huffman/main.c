#include "heap.h"

int main(int argc, char** argv) {
	size_t size = 10;
	struct Heap* heap = allocHeap(size);
	int arr[size];
	for (int i = 0; i < size; ++i) {
		struct Element cur;
		cur.key = 65 + size - i;
		cur.value = 0;
		insertElement(&cur, heap);
		printHeapArray(heap);
	}
	while (heap->tail != 0) {
		struct Element current = extractMin(heap);
		printf("The Key is : %c, Value is : %ld.\n", current.key, current.value);
	}

	return 0;
}
