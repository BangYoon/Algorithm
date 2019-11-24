// Heap Sort 힙 정렬 : Heapify Algorithm 사용 (특정 노드의 자식이 최대 힙 만족하는지 반복적으로 확인)
// O(N * logN)

#include<stdio.h>
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heap(int *heap, int size) {
	for (int i = 1; i < size; i++) {
		int child = i;

		while (child > 0) {
			int root = (child - 1) / 2;
			if (heap[root] < heap[child])
				swap(&heap[root], &heap[child]);
			child = root;
		}
	}
}

int main() {
	//int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };
	max_heap(heap, 9);
	
	for (int i = 9 - 1; i >= 0; i--) {
		// 가장 큰 숫자 root와 마지막 원소를 swap
		swap(&heap[i], &heap[0]);

		// 마지막 원소 제외하고 다시 heap 생성
		max_heap(heap, i);
	}
	
	for (int i = 0; i < 9; i++) 
		printf("%d ", heap[i]);
	
	return 0;
}
