#include <stdio.h>
int printarray(int *list, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", list[i]);
       // return list;
    }
}
void selection_sort(int *list, int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        temp = list[min];
        list[min] = list[i];
        list[i] = temp;
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
    selection_sort(list, n);
    printarray(list, n);


    return 0;
}