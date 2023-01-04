#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,4,3,2,1,7,6,8,4,9,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=7;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            cout<<"Element found at: "<<i;
            flag=false;
        }
    }
    if(flag)
        cout<<"Element not found";
}