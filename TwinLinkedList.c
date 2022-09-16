#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode(){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr->next=NULL;
    return ptr;
};

void print(struct node *start){
    start=start->next;
    while(start->next !=NULL){
        printf("%d ",start->data);
        start=start->next;
    }
}

int find(struct node * start,int i){
	start=start->next;
	int t;
    while(start->next !=NULL && i>=0){
        printf("\n%d ",start->data);
        t=start->data;
        start=start->next;
        i--;
    }
    printf("\nt=%d",t);
	return t;
}


void main(){
    struct node *start=newnode();
    struct node *ptr1=newnode();
    start->next=ptr1;
    int i,n,t;
    printf("Enter the size of linked list: ");
    scanf("%d",&n);
    if(n%2!=0){
    	printf("Odd number entered");
    	exit(-1);
	}
    printf("\nEnter the numbers: ");
    for(i=0;i<n;i++){
        scanf("%d",&t);
        struct node *present=newnode();
        ptr1->next=present;
        ptr1->data=t;
        ptr1=present;
    }
    printf("\nEntered numbers : ");
    print(start);
    int max=0;
    for(i=0;i<n/2;i++){
    	int x=find(start,i);
    	int y=find(start,n-1-i);
    	printf("x=%d,y=%d,sum=%d",x,y,x+y);
    	if(max<x+y){
    		max=x+y;
		}
	}
	printf("\nmax = %d",max);
}

