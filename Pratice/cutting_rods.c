#include "stdio.h"
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partation(int arr[],int low,int high){
    int pi=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(pi>=arr[j]){
            swap(arr+i,arr+j);
            i++;
        }
    }
    swap(arr+i, arr+high);
    return i;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partation(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n, L, i;
    printf("Enter the length of the rod: ");
    scanf("%d", &L);

    printf("Enter the number of pieces: ");
    scanf("%d", &n);
    int pieces[n];
    printf("Enter the lengths of the pieces: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pieces[i]);
    }
    quickSort(pieces,0,n-1);
    int cost=0;
    for(i=0;i<n-1;i++){
        cost+=pieces[i];
        printf("cut: %d, cost: %d\n",pieces[i],cost);
    }
    printf("Remaining cut: %d\n",pieces[i]);
    printf("Minimum cost: %d + %d = %d",L,cost,L+cost);
    return 0;
}