//Selection Sort 선택 정렬 : 나머지 중 가장 작은 수를 맨 앞에 놓기
//O(N^2)

include <stdio.h>
int main(){
	int num[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int i, j, min, index, temp;
	
	for (i = 0; i < 10; i++){
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > num[j]) {
				min = num[j];
				index = j;
			}
		}
		temp = num[i]; 
		num[i] = num[index];
		num[index] = temp;
	}

	for(i = 0; i < 10; i++){
		printf("%d ", num[i]);
	}
	return 0;
}
