#include<iostream>
using namespace std;
void mergeSort(int arr[],int m,int n);
void merge(int arr[],int p,int q,int r);
int main(){
    int arr[]={6,5,7,4,8,3,9,2,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void mergeSort(int arr[],int m,int n){
    if(m<n){
        int l=m+(n-m)/2;
        mergeSort(arr,m,l);
        mergeSort(arr,l+1,n);
        merge(arr,m,l,n);
    }
}

void merge(int arr[],int p,int q,int r){
    int a=q-p+1,b=r-q;
    int first[a],sec[b];
    for(int i=0;i<a;i++)
        first[i]=arr[p+i];
    for(int j=0;j<b;j++)
        sec[j]=arr[q+1+j];
    int i=0,j=0,k=p;
    while(i<a&&j<b){
        if(first[i]<sec[j]){
            arr[k]=first[i];
            i++;
        }
        else{
            arr[k]=sec[j];
            j++;
        }
        k++;
    }    
    while(i<a){
        arr[k]=first[i];
        i++;
        k++;
    }
    while(j<b){
        arr[k]=sec[j];
        j++;
        k++;
    }

}