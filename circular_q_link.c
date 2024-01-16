#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

int enqueue(struct node **front, struct node **rear, int data)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = NULL;

    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = newnode;
        newnode->next = *front; // Circular link
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
        newnode->next = *front; // Circular link
    }

    return 1;
}

int dequeue(struct node **front, struct node **rear)
{
    struct node *temp;

    if (*front == NULL && *rear == NULL)
    {
        return -1;
    }
    else if (*front == *rear)
    {
        free(*front);
        *front = *rear = NULL;
    }
    else
    {
        temp = *front;
        *front = (*front)->next;
        (*rear)->next = *front; // Circular link
        free(temp);
    }

    return 1;
}

void display(struct node **front, struct node **rear)
{
    struct node *temp;

    if (*front == NULL && *rear == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        temp = *front;

        do
        {
            printf(" %d ", temp->val);
            temp = temp->next;
        } while (temp != *front);

        printf("\n");
    }
}

int main()
{
    int ch, data, count1 = 0, count2 = 0;

    struct node *front = NULL;
    struct node *rear = NULL;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Count enueue number\n");
    printf("4. Count Dequeued number\n");
    printf("5. Display\n");

    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            if (enqueue)
            {
                count1++;
                printf("%d enqued succesfully", data);
            }
            break;

        case 2:
            dequeue(&front, &rear);
            if (dequeue)
            {
                count2++;
                printf("Dequeued succefully");
            }
            break;
        case 3:
            printf("%d", count1);
            break;
        case 4:
            printf("%d", count2);
            break;
        case 5:
            display(&front, &rear);
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
