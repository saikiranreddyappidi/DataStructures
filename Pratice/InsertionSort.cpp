#include<iostream>
using namespace std;
int main(){
    int arr[]={4,6,3,7,2,8,1,9,0,5},j;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int min=arr[i];
        for(j=i-1;j>=0 && min>arr[j];j--){
                arr[j+1]=arr[j];
        }
        arr[j+1]=min;
    } 
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}