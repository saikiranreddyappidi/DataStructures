#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define FIRST 0
#define MEDIAN 1
#define RANDOM 2

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int partitionFirst(int arr[], int low, int high)
{

    int pivot = arr[low];
    int k = high;
    for (int i = high; i > low; i--) {
        if (arr[i] > pivot)
            swap(&arr[i], &arr[k--]);
    }
    swap(&arr[low], &arr[k]);
    return k;
}

int partitionRandom(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    swap(&arr[random], &arr[low]);

    return partitionFirst(arr, low, high);
}

int partitionMedian(int arr[], int low, int high)
{
//        int r=0,s=high/2,t=high-1;
//    int r=high/4,s=high/2,t=3*high/4;
//    int mid = (r+s+t)/3;
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    return partitionFirst(arr, low, high);
}

void quickSort(int array[], int low, int high,int choice) {
    if (low < high) {
        int pivot;
        switch (choice) {
        case FIRST:
            pivot = partitionFirst(array, low, high);
            break;
        case MEDIAN:
            pivot = partitionMedian(array, low, high);
            break;
        case RANDOM:
            pivot = partitionRandom(array, low, high);
            break;
        }
        quickSort(array, low, pivot - 1,choice);
        quickSort(array, pivot + 1, high,choice);
    }
}

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6,8,9,3,2,5,1,8,0,12,15,45,64,2,1};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);
    int choice;
    printf("Enter 0 for first element as pivot, 1 for median of three as pivot and 2 for random element as pivot: ");
    scanf("%d",&choice);
    quickSort(data, 0, n - 1,choice);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}
