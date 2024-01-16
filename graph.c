#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a, size;
    int choice, i, j, edge, source, dest;
    int adjmat[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            adjmat[i][j] = 0;
        }
    }
    printf("Enter the no. of vertices");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        printf("Enter the value of %d vertex", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter the no. of edges");
    scanf("%d", &edge);

    for (i = 0; i < edge; i++)
    {
        printf("Enter %dth edge\n", i + 1);

        printf("Enter source position");
        scanf("%d", &source);
        source--;
        printf("Enter dest");
        scanf("%d", &dest);
        dest--;
        adjmat[source][dest] = 1;
        adjmat[dest][source] = 1;
    }

    printf("\nGraph:");
    printf("All vertices");
    for (i = 0; i < size; i++)
    {
        printf("\n%d. %d", i, a[i]);
    }
    printf("\nAdjacency matrix\n");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", adjmat[i][j]);
        }
        printf("\n");
    }
}