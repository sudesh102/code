#include <stdio.h>
#include <stdlib.h>
void shift_down(int *arr, int *last, int pos)
{
    int i;
    for (i = *last - 1; i >= pos - 1; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }
}
void shift_up(int pos, int *last, int *arr)
{
    int i;
    for (i = pos - 1; i < (*last); i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
}
void insert_at(int pos, int *last, int *arr, int data, int max)
{
    if (pos > *last)
        printf("Invalid Position");
    else if (pos > max)
        printf("Invalid Position");
    else
    {
        shift_down(arr, last, pos);
        *(arr + (pos - 1)) = data;
    }
    *last = *last + 1;
    return;
}
void insert_after_spe(int pos, int *last, int *arr, int data, int max)
{
    if (pos > *last)
        printf("Invalid Position");
    else if (pos > max)
        printf("Invalid Position");
    else
    {
        shift_down(arr, last, pos);
        *(arr + pos) = data;
    }
    *last++;
    return;
}
void delete_at(int pos, int *last, int *arr, int max)
{
    if (pos > max)
        printf("Invalid Position");
    else if (pos > (*last))
        printf("Invalid Position");
    else
        shift_up(pos, last, arr);

    *last = *last - 1;
}
void traverse(int *arr, int *last)
{
    printf("Elements in the list are\n");
    for (int i = 0; i < (*last - 1); i++)
    {
        printf(" %d", *(arr + i));
    }
    printf("\n");
}
int search(int data, int *arr, int *last)
{
    int i, flag = 0;
    for (i = 0; i < (*last); i++)
    {
        if (data == (*(arr + i)))
            flag = i;
    }
    if (flag == 0)
        return 0;
    else if (flag > 0)
    {
        return flag + 1;
    }
}
int main()
{
    int choice, temp = 1, ans;
    int arr[10], pos, last = 1, max = 10;
    int data;
    printf("Select which operation you want to perform\n");
    printf("Enter 1 for Inserting\n");
    printf("Enter 2 for deleting\n");
    printf("Enter 3 for searching\n");
    printf("Enter 4 for traverse\n");
    printf("Enter 5 for Exit\n");
    printf("Enter 6 add\n");
    while (1)
    {
        printf("Enter choice");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to store in the list:");
            scanf(" %d", &data);
            printf("Enter the position to store:");
            scanf(" %d", &pos);
            insert_at(pos, &last, arr, data, max);
            break;

        case 2:
            printf("Enter the position of the element to delete:");
            scanf(" %d", &pos);
            delete_at(pos, &last, arr, max);
            break;
        case 3:
            printf("Enter the element to search:");
            scanf(" %d", &data);
            ans = search(data, arr, &last);
            if (ans == 0)
                printf("The element is not present");
            else
                printf("The element is present at %d position", ans);
            break;
        case 4:
            traverse(arr, &last);
            break;
        case 5:
            exit(0);
        case 6:
            printf("Enter the data to store in the list:");
            scanf(" %d", &data);
            printf("Enter the position to store:");
            scanf(" %d", &pos);
            insert_after_spe(pos, &last, arr, data, max);
            break;
        default:
            printf("Enter a valid choice");
        }
    }
    // for (int i = 0; i < 10; i++)
    //     printf(" %d", arr[i]);
}
