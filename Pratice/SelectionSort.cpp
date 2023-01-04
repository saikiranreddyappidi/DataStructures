#include<iostream>
using namespace std;
int main(){
    int arr[]={3,7,8,4,9,1,6,2,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}