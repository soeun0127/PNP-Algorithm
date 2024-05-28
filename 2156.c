#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int count;
    scanf("%d", &count);

    int i;
    int* arr = (int*)malloc(sizeof(int) * count);
    int* sum_arr = (int*)malloc(sizeof(int) * count);

    for (i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }

    sum_arr[0] = arr[0];
    sum_arr[1] = arr[0] + arr[1];
    sum_arr[2] = max(sum_arr[1], max(arr[0] + arr[2], arr[1] + arr[2])); //세 가지 경우 중 제일 큰 값
    
    for (i = 3; i < count; i++) {
        sum_arr[i] = max(sum_arr[i - 1], max(sum_arr[i - 2] + arr[i], sum_arr[i - 3] + arr[i - 1] + arr[i]));
    }

    int max_result = 0;
    for (i = 1; i < count; i++) {
        if (max_result < sum_arr[i]) {
            max_result = sum_arr[i];
        }
    }

    printf("%d\n", max_result);

    free(arr);
    free(sum_arr);

    return 0;
}
