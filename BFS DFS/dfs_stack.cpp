// DFS : Depth First Search 깊이 우선 탐색
// 최상단 노드의 방문 안한 인접 노드가 있으면 스택에 넣고 없으면 최상단 노드 pop, 출력
// 컴터가 stack 기반이므로 #include<stack> 없어도 됨!

#include<stdio.h>
#include<vector>

using namespace std;
int visit[7];
vector<int> arr[8];


void dfs(int data) {
	if (visit[data] == 1) // 이미 방문했으면 break
		return;
	
	visit[data] = true;
	printf("%d ", data);

	for (int i = 0; i < arr[data].size(); i++) { // 인접한 노드 개수만큼
		int y = arr[data][i];
		dfs(y);
	}
}

void connect(int data1, int data2) {
	arr[data1].push_back(data2);
	arr[data2].push_back(data1);
}

int main() {
	// 인접한 노드 연결하기
	/*
	    8
	  2    3
	4  5  6  7
	*/

	connect(8, 2);
	connect(2, 4);
	connect(2, 5);

	connect(8, 3);
	connect(3, 6);
	connect(3, 7);

	connect(2, 3);
	connect(4, 5);
	connect(6, 7);

	dfs(8); // 8 2 4 5 3 6 7 순서로 출력

	return 0;
}
