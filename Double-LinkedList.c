#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *newnode(){
	struct node *ptr;
	ptr=malloc(sizeof(struct node));
	ptr->prev=NULL;
	ptr->next=NULL;
	return ptr;
}
int empty(struct node *start){
	return start->next->next==NULL;
}
int add(struct node *start){
	int val;
    printf("\nEnter a value: ");
    scanf("%d",&val);
    if(empty(start)){
    	start->next=newnode();
    	start->next->data=val;
    	return 1;
	}
	while(start->next!=NULL){start=start->next;}
    start->next=newnode();
    start->next->data=val;
    start->next->prev=start;
    return 1;
}
int delete(struct node *start){
	printf("\nEnter a value to delete: ");
	int val;
	scanf("%d",&val);
	while(start->data!=val){start=start->next;}
	start->prev->next=start->next;
	printf("\n%d is deleted",start->data);
	free(start);
	return 1;
}
int display(struct node *start){
	printf("\nThe following elements are in the List: ");
    while(start->next!=NULL){
    	printf("%d ",start->data);
    	start=start->next;
	}
	return 0;
}
int addafter_k(struct node *start){
	int cnt;
	printf("\nEnter the value of K: ");
	scanf("%d",&cnt);
	int t=cnt,s=0;
	while(cnt){
		if(start->next!=NULL){
			printf("\nList does not contain %d elements.It only contains %d elements.Adding element is not possible.",t,s);
			return 0;
		}
		cnt--;
		s++;
		start=start->next;
	}
	printf("\nEnter a value to add: ");
	int val;
	scanf("%d",&val);
	struct node * addelement=newnode();
	addelement->data=val;
	addelement->next=start->next;
	start->next=addelement;
	addelement->prev=start;
	addelement->next->prev=addelement;
	
}
int main(){
    int choice=1;
    struct node * start=newnode();
    while(choice!=0){
        printf("\n0-Exit\t1-Add Element\t2-Delete Element\t3-Display\t4-Add element after Kth element\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
        	add(start);
		}
        else if(choice==2){
        	if(empty(start)){
        		printf("\nUnderflow");
			}
			else{
				delete(start);
			}
		}
        else if(choice==3){
        	if(empty(start)){
        		printf("\nUnderflow:-No elements in the List");
			}
			else{
				display(start->next);
			}
		}
        else if(choice==4){
        	addafter_k(start);
		}
		else if(choice==0){
			return 0;
		}
        else
            printf("\nEnter a vaid choice.");                
    }
}
