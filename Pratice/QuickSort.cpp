#include<iostream>
using namespace std;
void quickSort(int arr[],int low,int high);
int partation(int arr[],int low,int high);
void swap(int *a,int *b);
int main(){
    int arr[]={5,4,6,3,7,2,8,1,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        return 0;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partation(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int partation(int arr[],int low,int high){
    int pi=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(pi>=arr[j]){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}