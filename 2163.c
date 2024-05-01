#include <stdio.h>

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	int count = 0;
	count = n - 1;
	count += n * (m - 1);
	printf("%d", count);
}
