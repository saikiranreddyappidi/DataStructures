#include<iostream>
using namespace std;

int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int low=0,high=n-1,mid=(low+high)/2;
    while(low<=high){
        if(arr[mid]==key){
            cout<<"Element found at: "<<mid;
            break;
        }
        else if(arr[mid]<key){
            cout<<"Element not found in left half of array";
            low=mid+1;
        }
        else{
            cout<<"Element not found in right half of array";
            high=mid-1;
        }
        mid=(low+high)/2;        
    }
}