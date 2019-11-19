#include<stdio.h>
int n, arr[1000000];

void quick(int *arr, int start, int end) {
	if (start >= end)
		return;

	int i, j, pivot, temp;
	pivot = start;
	i = start + 1;
	j = end;

	while (i <= j) {
		while (arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;

		if (i > j) {
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quick(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}