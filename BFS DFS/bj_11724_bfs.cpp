#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define max 10000

using namespace std;
vector<int> arr[max];
int visit[max];
int total;
vector<int> new_arr;

void bfs(int start) {
	for (int i = 0; i < new_arr.size(); i++) 
		if (new_arr[i] == start)return;

	int count = 0;
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	
	while (q.empty() != 1) {
		int x = q.front();
		q.pop();
		//printf("%d ", x);
		new_arr.push_back(x);

		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (visit[y] == 0) {
				q.push(y);
				visit[y] = 1;
			}
		}
	}
	total++;
}

int main() {
	int vertex, edge;
	int v1, v2, start;
	scanf("%d %d", &vertex, &edge);

	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &v1, &v2);

		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}
	
	for (int i = 1; i <= vertex; i++) {
		bfs(i);
		//printf("\n");
	}
	
	printf("%d\n", total);
	return 0;
}
