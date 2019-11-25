// Counting Sort 계수 정렬 : 특정 조건 (5 이하 숫자) 에서 단순히 개수를 세서 정렬 시키기
// O(N)

#include<stdio.h>

int main() {
	int temp;
	int count[6];
	int arr[30] = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2, 3, 4, 4, 3, 5, 1, 2, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 1, 1, 1 };

	for (int i = 1; i < 6; i++)
		count[i] = 0;

	for (int i = 0; i < 30; i++)
		count[arr[i]]++;
	
	for (int i = 1; i < 6; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				printf("%d ", i);
		}
	}

	return 0;
}
