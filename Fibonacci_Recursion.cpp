#include<iostream>
using namespace std;

int fibonacci(long long int x,long long int y,int k);

int main(){
    cout<<"Enter the no.of values needed: ";
    int x;
    cin>>x; 
    fibonacci(0,1,x);
}

int fibonacci(long long int x,long long int y,int k){
    cout<<x+y<<" "; 
    if(k!=0)
        return x+y+fibonacci(y,x+y,k-1);
    else
        return x+y;    
}
