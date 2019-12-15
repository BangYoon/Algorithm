// Queue - using linked list, both way
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev, *next;
}Node;

Node *head, *last;

void insert(int data) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;

	Node* cur = head->next;
	while (cur != last) { //to insert next to last node
		cur = cur->next;
	}

	Node* prev = cur->prev;
	prev->next = new;
	new->prev = prev;
	cur->prev = new;
	new->next = cur;
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void showAll() {
	Node* cur = head->next;
	while (cur != last) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void FreeAll() {
	Node* cur = head->next;
	while (cur != last) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(last);
	free(head);
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	last = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = last;
	last->prev = head;
	last->next = last;

	insert(2);
	insert(4);
	insert(1);
	insert(3);
	insert(5);
	removeFront();
	showAll();
	FreeAll();
	return 0;
}
