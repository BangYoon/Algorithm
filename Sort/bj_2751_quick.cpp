#include<stdio.h>
#include<algorithm>

int n, arr[1000000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	//Quick sort를 기반으로 하되, 별도의 처리과정이 있어 worst case인 O(n^2)을 없애줌!
	std::sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}
