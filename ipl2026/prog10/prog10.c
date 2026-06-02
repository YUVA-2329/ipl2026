#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = hoarePartition(arr, low, high);

        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {35, 12, 43, 8, 51, 27, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After Sorting:\n");
    printArray(arr, n);

    return 0;
}