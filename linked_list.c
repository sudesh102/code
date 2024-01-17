#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};

void Add_begin(struct node **,int);
void Add_middle(struct node **,int, int);
void Add_end(struct node **,int);
void Delete_begin(struct node **);
void Delete_middle(struct node **,int);
void Delete_end(struct node **);
void traverse(struct node **);
int search(struct node **,int);
void reverse();
int main()
{
    int ch, data, pos,count=0;
    struct node *head = NULL;
    printf("1.Add begin:\n");
    printf("2.Add middle:\n");
    printf("3.Add end:\n");
    printf("4.Delete begin:\n");
    printf("5.Delete middle:\n");
    printf("6.Delete end:\n");
    printf("7.Traverse:\n");
    printf("8.Search:\n");
    printf("9.Reverse list:\n");
    printf("10.Exit:\n");
    printf("11.count:\n");
    while (1)
    {
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data u want to insert:");
            scanf(" %d", &data);
            Add_begin(&head,data);
            if(data%2==0){
                count++;
            }
            break;
        case 2:
            printf("Enter the data u want to insert:");
            scanf("%d", &data);
            printf("Enter position where to insert data:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                Add_begin(&head,data);
            }
            else
                Add_middle(&head,data, pos);
            break;
        case 3:
            printf("Enter the data u want to insert:");
            scanf(" %d", &data);
            Add_end(&head,data);
            break;
        case 4:
            Delete_begin(&head);
            break;
        case 5:
            printf("Enter the postion at which u want to delete the data:");
            scanf("%d", &pos);
            Delete_middle(&head,pos);
            break;
        case 6:
            Delete_end(&head);
            break;
        case 7:
            traverse(&head);
            break;
        case 8:
            printf("Enter the data u want to search:");
            scanf("%d", &data);
            search(&head,data);
            break;
        case 9:
            printf("Before reversing the list:\n");
            traverse(&head);
            printf("\nAfter reversing the list:\n");
            reverse(&head);
            traverse(&head);
            break;
        case 10:
            exit(0);
            break;
            case 11:
            printf("%d",count);
            break;
        default:
            printf("Enter valid choice!!");
            break;
        }
    }
    printf("Enter the data u want to insert:");
    scanf("%d", &data);
}
void Add_begin(struct node **head,int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;
    if (head == NULL)
    {
        *head = temp;
        return;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}
void Add_middle(struct node **head,int data, int pos)
{
    struct node *newnode, *temp;
    temp = *head;
    int count = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = NULL;
    // if (pos == 1)
    // {
    //     newnode->next=head;
    //     head=newnode;
    // }
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void Add_end(struct node **head,int data)
{
    struct node *newnode, *temp;
    temp = *head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void Delete_begin(struct node **head)
{
    struct node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}
void Delete_middle(struct node **head,int pos)
{
    struct node *previous, *current;
    current = *head;
    int count = 0;
    if (*head == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        while (count < pos - 1)
        {
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        free(current);
    }
}
void Delete_end(struct node **head)
{
    struct node *previous, *current;
    current = *head;
    if (*head == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        free(current);
    }
}
void traverse(struct node **head)
{
    struct node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        while (temp != NULL)
        {
            printf(" %d ", temp->val);
            temp = temp->next;
        }
    }
}
int search(struct node **head,int data)
{
    struct node *temp;
    temp = *head;
    int flag = 0;
    while (temp->next != NULL)
    {
        if (temp->val == data)
        {
            flag++;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("Not found!");
    }
    else
    {
        printf("Found");
    }
}
void reverse(struct node **head)
{
    struct node *next_node, *prev_node, *current_node;
    prev_node = NULL;
    current_node = next_node ;
    if (*head == NULL)
    {
        *head;
    }
    else
    {
        while (current_node != NULL)
        {
            next_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }
    }
}