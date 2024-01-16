#include<stdio.h>

void bs(int a[], int size){
    for (int i = 0; i <size-1; i++){
        for (int j = 0; j <size-i-1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void ss(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void is(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }    
    
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    printf("\nBubble Sort:\n");
    bs(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Selection Sort
    printf("\nSelection Sort:\n");
    ss(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insertion Sort
    printf("\nInsertion Sort:\n");
    is(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}