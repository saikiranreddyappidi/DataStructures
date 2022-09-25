#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* previous;
    int data;
    struct node* next;
};

struct node* newnode(){
    struct node* ptr;
    ptr = malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->previous = NULL;
    return ptr;
}


void printreverse(struct node *start){
    while(start != NULL){
        printf("%d ",start->data);
        start=start->previous;
    }
}

int main(){
    struct node *start = newnode();
    int size,value;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&value);
        start->data = value;
        start->next = newnode();
        struct node *temp = start;
        start = start->next;
        start->previous = temp;
    }
    printreverse(start->previous);
}
