#include "list.h"

int main(int argc, char** argv) {
	struct List* list = allocList();
	for (int i = 0; i < 6; ++i) {
		struct Node* cur = malloc(sizeof(struct Node));
		cur->value = i;
		pushBack(cur, list);
	}
	printList(list);
	struct Node* first = malloc(sizeof(struct Node));
	first->value = 10;
	first->next = NULL;
	insertAt(first, 1, list);
	printList(list);

	struct Node* second = malloc(sizeof(struct Node));
	insertAt(second, 3, list);
	printList(list);
	
	struct Node* third = malloc(sizeof(struct Node));
	insertAt(third, 5, list);
	printList(list);
	return 0;
}
