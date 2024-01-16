#include <stdio.h>

void dfs(int arr[][100], int visited[], int vertices, int start)
{
   visited[start] = 1;
   int n, v,stack[100], top = -1;
   top++;
   stack[top] = start;
   while (top != -1)
   {
       v = stack[top];
       printf("%d ", v);
       top--;
       for (int i = 0; i < vertices; i++)
       {
           if (arr[v][i] == 1 && visited[i] == 0)
           {
               top++;
               stack[top]=i;
               visited[i]=1;
           }
       }
   }
}

int main()
{
   int n;
   printf("Enter number of nodes:");
   scanf("%d", &n);
   int arr[100][100], visited[100], vertices = n;
   for (int i = 0; i < n; i++)
   {
       visited[i] = 0;
   }
   printf("Enter your adjacency matrix:");
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           scanf("%d", &arr[i][j]);
       }
       printf("\n");
   }
   printf("DFS traversal: ");
   dfs(arr, visited, vertices, 0);
   return 0;
}
