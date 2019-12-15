// BFS : Breath First Search 너비 우선 탐색
// 첫 노드부터 인접한 노드들 Queue에 넣어주기

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<int> arr[8];
int visit[7];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true; //방문 처리

	while (q.empty() == 0) { // q가 비어있지 않으면
		int x = q.front();
		q.pop();
		printf("%d ", x); //인접한 노드 순서대로 출력
		for (int i = 0; i < arr[x].size(); i++) { //x의 인접 노드 개수만큼
			int y = arr[x][i];
			if (visit[y] == 0) { // y가 아직 방문안된 경우 
				q.push(y);
				visit[y] = true;
			}
		}
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

	bfs(8); // 8 2 3 4 5 6 7 순서로 출력
	return 0;
}
