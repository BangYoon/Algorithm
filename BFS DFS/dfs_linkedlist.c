#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int vertex;
	struct Node* next;
}Node;

Node** graph;
int vertex, edge;
int visit[10] = { 0 };

void addVertex(Node* root, int vertex) { // same with addFront
	Node* new = (Node*)malloc(sizeof(Node));
	new->vertex = vertex;
	new->next = root->next;
	root->next = new;
}

void dfs(int vertex) {
	if (visit[vertex] == 1) 
		return;

	visit[vertex] = 1;
	printf("%d ", vertex);
	Node* cur = graph[vertex]->next; //cur = adjacent vertex node
	while (cur != NULL) {
		dfs(cur->vertex);
		cur = cur->next;
	}
}

int main() {
	int src, dest;
	scanf("%d %d", &vertex, &edge);

	graph = (Node**)malloc(sizeof(Node*)*vertex);
	for (int i = 1; i <= vertex; i++) { //vertex should be start with '1'
		graph[i] = (Node*)malloc(sizeof(Node));
		graph[i]->next = NULL;
	}

	for (int i = 0; i < edge; i++) { // undirected(bothway) unweighted graph
		scanf("%d %d", &src, &dest);
		addVertex(graph[src], dest);
		addVertex(graph[dest], src);
	}

	dfs(1);
	return 0;
}
