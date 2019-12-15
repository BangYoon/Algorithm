// Queue - FIFO
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *head;

void push(Node* root, int data) { // add front -> 5 4 3 2 1
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = root->next;
	root->next = new;
}

void pop(Node* root) { //remove front(x) last(o) -> 5 4 3 2
	if (root->next == NULL)
		printf("-1\n");
	else if(root->next->next == NULL){
		Node* cur = root->next;
		printf("%d\n", cur->data);
		root->next = NULL;
		free(cur);
	} 
	else {
		Node* cur = root->next;
		while ((cur->next)->next != NULL) {
			cur = cur->next;
		}
		printf("%d\n", (cur->next)->data);
		free(cur->next);
		cur->next = NULL;
	}
}

void size(Node* root) {
	int n = 0;
	Node* cur = root->next;
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}
	printf("%d\n", n);
}

void empty(Node* root) {
	if (root->next == NULL)
		printf("1\n");
	else
		printf("0\n");
}

void back(Node* root) { // print front
	if (root->next == NULL)
		printf("-1\n");
	else {
		Node* cur = root->next;
		printf("%d\n", cur->data);
	}
}

void front(Node* root) { // print last
	if (root->next == NULL)
		printf("-1\n");
	else {
		Node* cur = root->next;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		printf("%d\n", cur->data);
	}
}

int make_num(char* str) {
	for (int i = 0; i < 10; i++) {
		if (atoi(&str) == i){ //atoi : make string to int
			return i;
			break;
		}
	}
}

int main() {
	int num, push_num;
	char str[10] = {0};
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	scanf("%d", &num);
		
	while (num >= 0) {
		gets(str);
	
		if (str[1]== 'u') {
			//printf("%c\n", str[5]);
			push_num = make_num(str[5]);
			//printf("%d\n", push_num);
			push(head, push_num);
		}
		else if (strcmp(str, "front") == 0) {
			front(head);
		}
		else if (strcmp(str, "back") == 0) {
			back(head);
		}
		else if (strcmp(str, "size") == 0) {
			size(head);
		}
		else if (strcmp(str, "pop") == 0) {
			pop(head);
		}
		else if (strcmp(str, "empty") == 0) {
			empty(head);
		}
		num--;
	}


	return 0;
}
