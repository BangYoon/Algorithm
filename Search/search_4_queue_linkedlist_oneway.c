// Queue - using linked list, one way
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node * head;

void addFront(Node* root, int data) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = root->next;
	root->next = new;
}

void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next;
	free(front);
}

void printAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void freeAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(root);
}

int main() {
	head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;

	head->next = node1;
	node1->next = node2;
	node2->next = NULL;

	printAll(head);

	printf("Add 3 in front\n");
	addFront(head, 3);
	printAll(head);

	printf("Remove front\n");
	removeFront(head);
	printAll(head);

	printf("Remove front\n");
	removeFront(head);
	printAll(head);

	freeAll(head);
	return 0;
}
