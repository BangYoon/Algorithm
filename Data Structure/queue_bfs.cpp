// BFS : Breath First Search 너비 우선 탐색
// 첫 노드부터 인접한 노드들 큐에 넣어주기

#include<iostream>
#include<queue>
#include<vector> // 데이터 저장

using namespace std;
int visit[7];
vector<int> arr[8];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true; //방문했다고 처리

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < arr[x].size(); i++) { //꺼낸 노드의 인접한 노드들 개수 만큼
			int y = arr[x][i];
			if (!visit[y]) {
				q.push(y);
				visit[y] = true;
			}
		}
	}
}

int main() {
	// 인접한 노드들 연결하기
	/*
		   8
		 2   3
		4 5  6 7
	*/

	arr[8].push_back(2);
	arr[2].push_back(8);

	arr[8].push_back(3);
	arr[3].push_back(8);

	arr[2].push_back(4);
	arr[4].push_back(2);

	arr[2].push_back(5);
	arr[5].push_back(2);

	arr[3].push_back(6);
	arr[6].push_back(3);

	arr[3].push_back(7);
	arr[7].push_back(3);

	/*
	arr[4].push_back(5);
	arr[5].push_back(4);

	arr[6].push_back(7);
	arr[7].push_back(6);
	*/
	bfs(8);
	return 0;
}
