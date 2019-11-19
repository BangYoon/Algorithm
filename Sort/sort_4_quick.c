// Quick Sort 퀵 정렬 : 분할 정복 알고리즘! 특정값(pivot)을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤 배열을 반으로 나누기 
// O(N*longN) ~ O(N^2) - 이미 정렬되어 있는 경우가 최악!

#include<stdio.h>
void quick(int* arr, int start, int end) {
	if (start >= end)
		return 0; // 원소가 1개인 경우 그대로 두기

	int i, j, pivot, temp;
	pivot = start;
	i = start + 1; //pivot보다 큰수, 왼쪽부터
	j = end;//pivot보다 작은수, 오른쪽부터

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i >= j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quick(arr, start, j - 1);
	quick(arr, j + 1, end);
}
int main() {
	int arr[10] = {3, 10, 9, 2, 4, 1, 6, 8, 5, 7};
	int i;
	
	quick(arr, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}
