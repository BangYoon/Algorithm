#include<stdio.h>
// Insertion Sort 삽입 정렬 : 앞부터 각 숫자를 적절한 위치에 삽입하기 (필요할 때만 위치 변경!)
// O(N) ~ O(N^2)
int main() {
	int arr[10] = { 2, 9, 8, 1, 10, 6, 4, 7, 3, 5 };
	int i, j, temp;

	for (i = 0; i < 9; i++) {
		j = i;
		while (/*j>=0 &&*/ arr[j] > arr[j+1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}


	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}
