// Merge Sort 병합 정렬 : 일단 반으로 나누고, 합치면서 정렬하기
// O(N * logN) wort case에도 보장!

#include<stdio.h>
int sorted[8]; //정렬 배열 반드시 전역 변수로 선언

void merge(int arr[], int start, int middle, int end) {
	int i, j, k;
	i = start;
	j = middle + 1;
	k = start;

	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	//남은 데이터도 삽입
	if (i > middle) { //앞 집합은 전부 삽입된 상태
		for (int t = j; t <= end; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else { //뒷 집합이 전부 삽입된 상태
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}

	//정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		arr[t] = sorted[t];
	}

}

void merge_sort(int arr[], int start, int end) {
	//나뉘어진 집합 크기가 1인 경우 (맨 처음)
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
}

int main() {
	int arr[8] = { 2, 4, 5, 1, 7, 3, 8, 6 };

	merge_sort(arr, 0, 7);

	for (int t = 0; t < 8; t++)
		printf("%d ", arr[t]);

	return 0;
}
