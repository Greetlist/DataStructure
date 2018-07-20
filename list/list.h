#ifndef __LIST_H__
#define __LIST_H__

#include "node.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct List {
	struct Node* head;
	struct Node* tail;
	int len;
};

extern struct List* allocList();

extern void pushBack(struct Node* node, struct List* list);

extern struct Node* removeNodeAt(int index, struct List* list);

extern void insertAt(struct Node* node, int index, struct List* list);

extern void printList(const struct List* list);

#endif
