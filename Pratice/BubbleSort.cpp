#include<iostream>
using namespace std;
int main(){
    int arr[]={4,3,5,6,2,7,1,8,0,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool opt=true;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                int t=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
                opt=false;// optimization
            }
        }
        if(opt)
            break;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}