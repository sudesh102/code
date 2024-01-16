#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int push(int *a, int *top, int data)
{
    if ((*top) == MAX - 1)
    {
        return -1;
    }
    else
    {
        (*top) = (*top) + 1;
        a[*top] = data;
        return 0;
    }
}
int pop(int *a, int *top)
{
    int item;
    if (*top == -1)
    {
        return -1;
    }
    else
    {
        item = a[*top];
        (*top)--;
        return item;
    }
}
int display(int *a, int *top)
{
    for (int i = 0; i <= *top; i++)
    {
        printf(" %d ", a[i]);
    }
}
void main()
{
    int data, ch, count1 = 0, result = 0, top = -1;
    int a[MAX];
    printf("1.Push operation\n");
    printf("2.pop operation\n");
    printf("3.peek operation\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf("6.count\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            result = push(a, &top, data);
            if (result == -1)
            {
                printf("\nstack if overflow");
            }
            else
            {
                printf("\nData is added succefully");
            }
            if (push)
            {
                count1++;
            }
            break;
        case 2:
            result = pop(a, &top);
            if (result == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("The poped element is:%d", result);
                count1--;
            }
            
            break;
        case 3:
            printf("%d", a[top]);
            break;
        case 4:
            display(a, &top);
            break;
        case 5:
            exit(0);
        case 6:
            printf("%d", count1);
            break;
        default:
            printf("Enter the valid choice");
        }
    }
}
