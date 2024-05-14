#include <stdio.h>

int arr[300];
int step[300];

int Max(int a, int b) {
	if(a > b) return a;
  else return b;
}
int main() {

	int cnt, max;

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) { //step 입력
		scanf("%d", &step[i]);
	}

	arr[0] = step[0];
	arr[1] = step[0] + step[1];
	arr[2] = Max(step[0] + step[2], step[1] + step[2]);

	for (int i = 3; i < cnt; i++) {
		arr[i] = Max(arr[i - 2] + step[i], arr[i - 3] + step[i - 1] + step[i]);
	}

	printf("%d", arr[cnt - 1]);

	return 0;
}
