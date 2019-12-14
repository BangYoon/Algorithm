#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node * head, *last;

void insertLast(int data) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;

	Node* cur = head->next;
	while (cur != last) {
		cur = cur->next;
	}

	Node* prev = cur->prev;
	prev->next = new;
	new->prev = prev;
	cur->prev = new;
	new->next = cur;
}

void removeFront() {
	Node* front = head->next;
	head->next = front->next;
	Node* next = front->next; // = head->next;
	next->prev = head;
	free(front);
}

void printAll() {
	Node* cur = head->next;
	while (cur != last) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void freeAll() {
	Node* cur = head->next;
	while (cur != last) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(last);
	free(head);
}

int main() {
	head = (Node*)malloc(sizeof(Node));
	last = (Node*)malloc(sizeof(Node));

	head->prev = head;
	head->next = last;
	last->prev = head;
	last->next = last;

	printf("Insert 2017\n");
	insertLast(2);
	insertLast(0);
	insertLast(1);
	insertLast(7);
	printAll();
	printf("Delete two\n");
	removeFront();
	removeFront();
	printAll();

	freeAll();
	return 0;

}
