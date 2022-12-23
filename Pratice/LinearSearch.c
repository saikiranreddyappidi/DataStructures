#include "stdio.h"
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==5){
            printf("Found at %d",i);
            break;
        }
    }
}