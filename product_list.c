#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    int pro_id;
    char name[50];
    int quantity;
    float price;
    float GST;
    struct list *next;
};

void Add_to_cart(struct list **head, int id, int qua, char *name, float pri, float gst)
{
    struct list *new_pro, *temp;
    new_pro = (struct list *)malloc(sizeof(struct list));
    new_pro->pro_id = id;
    strcpy(new_pro->name, name);
    new_pro->quantity = qua;
    new_pro->price = pri;
    new_pro->GST = gst;
    new_pro->next = NULL;

    if (*head == NULL)
    {
        *head = new_pro;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_pro;
    }
}

int delete_pro(struct list **head, int pos)
{
    struct list *prev, *current;
    current = *head;
    int len = 0, i;

    while (current != NULL)
    {
        len++;
        current = current->next;
    }

    if (*head == NULL || pos < 1 || pos > len)
    {
        return -1;
    }

    current = *head;

    if (pos == 1)
    {
        *head = current->next;
        free(current);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free(current);
    }
    return 0;
}

void display(struct list **head)
{
    struct list *temp;
    temp = *head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, GST: %.2f\n",
                   temp->pro_id, temp->name, temp->quantity, temp->price, temp->GST);
            temp = temp->next;
        }
    }
}

int search(struct list **head, int id)
{
    struct list *temp;
    temp = *head;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->pro_id == id)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if (flag == 0)
    {
        return -1;
    }

    return 0;
}

int main()
{
    struct list *head = NULL;
    int ch, id, qua, pos, x;
    float pri, gst;
    char name[50];

    printf("1. Add to cart:\n");
    printf("2. Delete product:\n");
    printf("3. Search product:\n");
    printf("4. Display the product list:\n");
    printf("5. Stop\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter product ID: ");
            scanf("%d", &id);
            printf("Enter the product name: ");
            scanf("%s", name);
            printf("Enter the Quantity of product: ");
            scanf("%d", &qua);
            printf("Enter the price: ");
            scanf("%f", &pri);
            printf("Enter GST: ");
            scanf("%f", &gst);
            Add_to_cart(&head, id, qua, name, pri, gst);
            break;

        case 2:
            printf("\nEnter the position to delete product: ");
            scanf("%d", &pos);
            x = delete_pro(&head, pos);
            if (x == -1)
            {
                printf("The list is empty or position is invalid!\n");
            }
            else
            {
                printf("Product deleted successfully.\n");
            }
            break;

        case 3:
            printf("Enter the product id to find product: ");
            scanf("%d", &id);
            x = search(&head, id);
            if (x == -1)
            {
                printf("Product is not present.\n");
            }
            else
            {
                printf("Product is present.\n");
            }
            break;

        case 4:
            display(&head);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
