// #include <stdio.h>
// #include <stdlib.h>
// #define max 20
// struct node
// {
//     int arr[max];
//     int front;
//     int rear;
// };
// void enqueue(struct node *q, int data)
// {
//     if (q->rear == max - 1)
//     {
//         printf("Overflow\n");
//     }
//     else
//     {
//         if (q->rear == -1 && q->front == -1)
//         {
//             q->rear = data;
//         }
//         q->rear++;
//         q->arr[q->rear] = data;
//     }
// }
// int dequeue(struct node *q)
// {
//     if (q->front == -1 && q->rear == -1)
//     {
//         printf("Underflow\n");
//         return -1;
//     }
//     else
//     {
//         int data = q->arr[q->front];
//         if (q->front == q->rear)
//         {
//             q->front = -1;
//             q->rear = -1;
//         }
//         else
//         {
//             q->front++;
//         }
//         return data;
//     }
// }
// void traverse(struct node *q)
// {
//     if (q->rear == -1 && q->front == -1)
//     {
//         printf("Empty");
//     }
//     else
//     {
//         for (int i = q->front; i <= q->rear; i++)
//         {
//             printf(" %d ", q->arr[i]);
//         }
//     }
// }
// int main()
// {
//     struct node q;
//     q.front = -1;
//     q.rear = -1;
//     printf("1.Enqueue\n");
//     printf("2.Dequeue\n");
//     printf("3.Traverse\n");
//     printf("4.Exit\n");
//     int ch, data, x;
//     while (1)
//     {
//         printf("\nEnter your choice:");
//         scanf("%d", &ch);
//         switch (ch)
//         {
//         case 1:
//             printf("Enter the data to enqueue:");
//             scanf("%d", &data);
//             enqueue(&q, data);
//             break;
//         case 2:
//             data = dequeue(&q);
//             if (data != -1)
//             {
//                 printf("Dequeued data: %d\n", data);
//             }
//             break;
//         case 3:
//             traverse(&q);
//             break;
//         case 4:
//             exit(0);
//         default:
//             printf("Enter the valid chouice!!");
//         }
//     }
//     return 0;
// }


#include <stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
{
    int arr[MAX];
    int front;
    int rear;
};

int enqueue(struct node *q, int data)
{
    if (q->rear == MAX - 1)
    {
        return -1;// overflow
    }
    else
    {
        if (q->rear == -1 && q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
    return 0;
}

int dequeue(struct node *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        int data = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
        return data;
    }
}

void traverse(struct node *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
    
    }
}

int main()
{
    struct node q;
    q.front = -1;
    q.rear = -1;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");

    int choice, data,result;
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            result=enqueue(&q, data);
            if(result==-1){
                printf("underflow");
            }
            else{
                printf("data is enqueud");
            }
            break;
        case 2:
            data = dequeue(&q);
            if (data != -1)
            {
                printf("Dequeued data: %d\n", data);
            }
            break;
        case 3:
            traverse(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
