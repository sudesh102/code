#include <stdio.h>
#include <stdlib.h>
#define size 5
int que[size], front = -1, rear = -1;
int enqueue(int data)
{
    if (rear = size - 1)
    {
        return -1;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        que[rear] = data;
    }
    else
    {
        rear++;
        que[rear] = data;
    }
}
int dequeue()
{
    if (front == -1 && rear == -1)
    {
        return -1;
    }
    else if (front == rear)
    {
        front == rear == -1;
    }
    else
    {
        front++;
        return front;
    }
}
void display(){
    int i=front,j=rear;
    if (front == -1 && rear == -1)
    {
        printf("empty");
    }
    else{
        do{
            printf("%d",que[i]);
            i=i+1;
        }while(i!=j);
            
    }
}
int main()
{
    int data, ch, x;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            x = dequeue();
            if (x == -1)
            {
                printf("Empty");
            }
            else
            {
                printf("the dequeued element is:%d", data);
            }
            break;
            case 3:
            display();
            break;
        }
    }
    return 0;
}