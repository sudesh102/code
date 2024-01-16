#include <stdio.h>
int binary_search(int arr[], int n, int data)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data == arr[mid])
        {
            return mid;
        }
        else if (data < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n], data;
    printf("Enter the aaray element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the data u want to search:");
    scanf("%d", &data);
    int result = binary_search(arr, n, data);
    if (result != -1)
    {
        printf("The element is fount at index:%d", result);
    }
    else
    {
        printf("not found");
    }
    return 0;
}
