#include <stdio.h>
int bub(int list[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1 - i; j++)
        {
            if (list[j] > list[j + 1])
            {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    return list;
}
void printarr(int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", list[i]);
    }
}
int main()
{
    int n, sorted;
    printf("Enter the size:");
    scanf("%d", &n);
    int list[n];
    printf("array ele:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    sorted = bub(list, n);
    printarr(list, n);
    return 0;
}