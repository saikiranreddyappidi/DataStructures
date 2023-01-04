#include<iostream>
using namespace std;

int main(){
    int arr[]={2,4,5,7,11,15,18,100},key=11;
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0,high=n,mid=(low+high)/2;
    while(low<=high){
        if(arr[mid]==key){
            cout<<"Element found at: "<<mid;
            break;
        }
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
        mid=(low+high)/2;        
    }
}