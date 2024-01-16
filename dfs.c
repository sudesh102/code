#include <stdio.h>
int dfs(int start, int vertices, int visited[], int a[5][5]);
int main()
{
    int a[5][5], visited[5], vertices, q, w;
    printf("enter no of vertices");
    scanf("%d", &vertices);
    for (int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }
    printf("enter your matrix");
    for (int q = 0; q < 5; q++)
    {
        for (w = 0; w < 5; w++)
        {
            scanf("%d", &a[q][w]);
        }
    }
    dfs(0, vertices, visited, a);
}
int dfs(int start, int vertices, int visited[], int a[5][5])
{
    visited[start] = 1;
    int stack[5];
    int top = -1, v, i;
    top++;
    stack[top] = start;
    while (top != -1)
    {
        v = stack[top];
        printf("%d", v);
        top--;
        for (i = 0; i < vertices; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                top++;
                stack[top] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
