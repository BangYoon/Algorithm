// Queue - FIFO
#include<stdio.h>
#include<queue>

using namespace std;

int main() {
	queue<int> q;
	int num, push_num;
	char str[10] = { 0 };

	scanf("%d", &num);

	while (num > 0) {
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &push_num);
			q.push(push_num);
		}
		else if (!strcmp(str, "front")) {
			printf("%d\n", q.front());
		}
		else if (!strcmp(str, "back")) {
			printf("%d\n", q.back());
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(str, "pop")) {
			if (q.empty() == 1)
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else
			printf("%d\n", q.empty());
		num--;
	}
	return 0;
}
