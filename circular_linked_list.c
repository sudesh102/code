#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
void add_begin(struct node **, int);
void add_end(struct node **, int);
void add_specific(struct node **, int, int);
void display(struct node **);
void main()
{
    int data, pos, ch;
    struct node *head = NULL;
    printf("1.Add at begin:\n");
    printf("2.Add at end:\n");
    printf("3.Add at specific:\n");
    // printf("4.Delete at begin:\n");
    // printf("5.Delete at end:\n");
    // printf("6.Delete at specific:\n");
    printf("7.Display:\n");
    printf("8.Exit:\n");
    while (1)
    {
        printf("\nEnter youe choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data u want to insert:");
            scanf("%d", &data);
            add_begin(&head, data);
            break;
        case 2:
            printf("Enter the data u want to insert:");
            scanf("%d", &data);
            add_end(&head, data);
            break;
        case 3:
            printf("Enter the data u want to insert:");
            scanf("%d", &data);
            printf("Enter the positon at which u want to insert data:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                add_begin(&head, data);
            }
            else
            {
                add_specific(&head, data, pos);
            }
            break;
        case 7:
            display(&head);
            break;
        case 8:
            exit(0);
        default:
            printf("Enter valid choice!");
        }
    }
}
void add_begin(struct node **head, int data)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = *head;
    temp = *head;
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
    }
    else
    {
        do
        {
            temp = temp->next;
        } while (temp->next != *head);
        newnode->next = *head;
        *head = newnode;
        temp->next = newnode;
    }
}
void add_end(struct node **head, int data)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = *head;
    temp = *head;
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
    }
    else
    {
        do
        {
            temp = temp->next;
        } while (temp->next != *head);
        
    }
}
void add_specific(struct node **head, int data, int pos)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = *head;
    temp = *head;
    int i = 1;
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
    }
    else
    {
        do
        {
            temp = temp->next;
            i++;
        } while (i < pos - 1);
        newnode->next=temp->next;
        temp->next = newnode;
    }
}
void display(struct node **head)
{
    struct node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("List is Empty!!");
    }
    else
    {
        do
        {
            printf(" %d ", temp->val);
            temp = temp->next;
        } while (temp != *head);
    }
}