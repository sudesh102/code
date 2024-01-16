#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
int push(int data, struct node **top)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = *top;
    // if(*top==NULL){
    //     *top = newnode;
    // }
    // *top=(*top)->next;
    *top = newnode;
}
int pop(struct node **top)
{
    struct node *temp;
    
    if (*top == NULL)
    {
        return -1;
    }
    temp = *top;
    int item = temp->val;
    (*top) = (*top)->next;
    free(temp);
    return item;
}
int peek(struct node **top)
{
    if (*top == NULL)
    {
        return -1;
    }
    else
    {
        return (*top)->val;
    }
}
void display(struct node **top)
{
    struct node *temp;
    temp = *top;
    if (*top == NULL)
    {
        printf("Stack empty");
    }
    else
    {
        while (temp!= NULL)
        {
            printf(" %d ",temp->val);
            temp = temp->next;
            
        }
        
        printf("\n");
    }
}
void main()
{
    int data, ch, result = 0;
    struct node *top = NULL;
    printf("1.Push operation\n");
    printf("2.pop operation\n");
    printf("3.peek operation\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data u want to addd in stack:");
            scanf("%d", &data);
            push(data, &top);
            // if (result == -1)
            // {
            //     printf("Data does not push");
            // }
            // else
            // {
            //     printf("\nData is pushed");
            // }
            break;

        case 2:
            result = pop(&top);
            if (result == -1)
                printf("Stack underflow");
            else
                printf("Data popped:%d", result);
            break;
        case 3:
            result = peek(&top);
            if (result == -1)
                printf("Stack underfow");
            else
                printf("Top element:%d", result);
            break;
        case 4:
            display(&top);
            break;
        }
    }
}
