// Bubble Sort 버블 정렬 : 옆에 있는 값과 비교해서 더 작은 값을 앞으로 보내기
// O(N^2) - 가장 비효율적

#include<stdio.h>
int main() {
	int arr[10] = {9, 8, 1, 2, 10, 6, 4, 7, 3, 5};
	int i, j, temp;
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
