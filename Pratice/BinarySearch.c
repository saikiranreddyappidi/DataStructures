#include "stdio.h"
int main(){
    int arr[]={0,5,15,23,25,26,34,35};
    int length=sizeof (arr)/sizeof (arr[0]);
    int low=0,high=length,mid=(low+high)/2;
    int find=25;
    for(int i=0;i<length;i++){
        if(arr[mid]==find) {
            printf("Element found at %d", mid);
            break;
        }
        else if(arr[mid]>find)
            high=mid-1;
        else
            low=mid+1;
        mid=(low+high)/2;
    }
}
//time complexity
//O(log n)
/*each time the size of array becomes half
 * initially len=n
 * in first iteration the length=n/2
 * second iteration n/4
 * n/8
 *.
 * .
 * .
 * so it becomes n/2^k
 * finally the length of the array becomes 1
 * n/2^k=1
 * log n=log2^k
 * k=log n
 * */