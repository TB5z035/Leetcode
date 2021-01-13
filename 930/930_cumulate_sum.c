#include <stdio.h>
#include <stdlib.h>

int numSubarraysWithSum(int *A, int ASize, int S)
{
    int *sum, *map;
    int i, cnt;
    sum = (int *)malloc((ASize + 1) * sizeof(int));
    sum[0] = 0;
    for (i = 0; i < ASize; i++)
        sum[i + 1] = sum[i] + A[i];
    map = (int *)malloc((sum[ASize] + S + 1) * sizeof(int));
    for (i = 0; i < sum[ASize] + S + 1; i++)
    {
        map[i] = 0;
    }
    cnt = 0;
    for (i = 0; i < ASize + 1; i++)
    {
        cnt += map[sum[i]];
        map[sum[i] + S]++;
    }
    return cnt;
}

int main()
{
    int arr[] = {1, 0, 1, 0, 1};
    int size = 5;
    int S = 2;
    printf("\n%d\n", numSubarraysWithSum(arr, size, S));
    return 0;
}