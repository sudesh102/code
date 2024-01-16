#include <stdio.h>
void inserction_sort(int a[], int size)
{
    int j, temp;
    for (int i = 1; i <= size; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int n;
    printf("Enter the array size:");
    scanf("%d", &n);
    int list[n];
    printf("Enter the array element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    inserction_sort(list, n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", list[i]);
    }
    return 0;
}