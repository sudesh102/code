#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of nodes of graph:");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the graph matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((i != j) && (arr[i][j] == 0) && (arr[i][k] == 1) && (arr[k][j] == 1))
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
    printf("The path matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}