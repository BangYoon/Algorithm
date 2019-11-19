#include<stdio.h>
#include<algorithm>

 int arr[1000];

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int n, temp;
	int len = 0;

	scanf("%d", &n);
	temp = n;

	while ((n / 10) > 0) {
		n = n / 10;
		len++;
	}
	len++;
	//printf("%d", len);

	for (int i = 0; i < len; i++) {
		arr[i] = temp % 10;
		//printf("%d ", arr[i]);
		temp = temp / 10;
	}
	
	std::sort(arr, arr + len, desc);
	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);
	
	return 0;
}
