#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
int enqueue(struct node **front,struct node**rear,int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=data;
    newnode->next=NULL;
    if(*front==NULL&&*rear==NULL){
        *front=*rear=newnode;
    }
    else{
        (*rear)->next=newnode;
        *rear=newnode;
    }
}
int dequeue(struct node **front,struct node **rear)
{
    struct node *temp;
    temp=*front;
    if(*front==NULL && *rear==NULL){
        printf("empty");
        return -1;
    }
    else if(*front==*rear){
        free(temp);
        *front=*rear=NULL;
    }
    else{
        temp=temp->next;
        free(temp);
    }
}
void display(struct node **front,struct node**rear,int data){
    struct node *temp;
    temp=*front;
    if(*front==NULL&&*rear==NULL){
       printf("Empty");
    }
    else{
        while(temp!=NULL){
            printf(" %d ",temp->val);
            temp=temp->next;
        }
    }

}
int main()
{
    int ch,data,x;
    struct node *front = NULL;
    struct node *rear = NULL;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            enqueue(&front,&rear,data);
            break;
            case 2:
            dequeue(&front,&rear);
            break;
            case 3:
             display(&front,&rear,data);
        
            break;
        }
    }
    return 0;
}
