#include "list.h"

extern struct List* allocList() {
	struct List* returnPtr = malloc(sizeof(struct List));
	if (returnPtr == NULL) {
		perror("Malloc Failed");
	} else {
		memset(returnPtr, 0, sizeof(struct List));
	}
	return returnPtr;
}

extern void pushBack(struct Node* node, struct List* list) {
	if (list->len == 0) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
	list->len++;
}

extern struct Node* removeNodeAt(int index, struct List* list) {
	struct Node* returnPtr = NULL;
	if (index <= 0) {
		returnPtr = list->head;
		list->head = list->head->next;
		returnPtr->next = NULL;
	} else if (index > list->len) {
		returnPtr = list->tail;
		struct Node* cur = list->head;
		while (cur->next != NULL && cur->next != list->tail) {
			cur = cur->next;
		}
		list->tail = cur;
		list->tail->next = NULL;
	} else {
		int curIndex = 1;
		struct Node* pre = list->head;
		while (curIndex++ < index) {
			pre = pre->next;
		}
		returnPtr = pre->next;
		pre->next = pre->next->next;
		returnPtr->next = NULL;
	}
	return returnPtr;
}

extern void insertAt(struct Node* node, int index, struct List* list) {
	if (index > list->len) {
		pushBack(node, list);
	} else if (index <= 0) {
		node->next = list->head;
		list->head = node;
	} else {
		int curIndex = 1;
		struct Node* pre = list->head;
		while (curIndex++ < index) {
			pre = pre->next;
		}
		node->next = pre->next;
		pre->next = node;
	}
}

extern void printList(const struct List* list) {
	struct Node* cur = list->head;
	while (cur != NULL) {
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}
