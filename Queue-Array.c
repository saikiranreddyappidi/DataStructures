#include<stdio.h>
#include<stdlib.h>
int queue[5],front=-1,rear=-1,max=5;
int Enqueue(){
    rear++;
    if(front==-1)
        front=0;
    if(rear>5){
        printf("Queue is full.");
    	return 0;
    }
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    queue[rear]=value;
}
int Dequeue(){
    if(rear==-1 || front>rear){
        printf("Queue is empty.");
    }
    else{
    	printf("%d is deleted from the queue.",queue[front]);
    	front++;
	}
    return 0;    
}
int display(){
    if(rear==-1 || front>rear){
        printf("Queue is empty.");
    }
    else{
    	int i;
    	printf("The following elements are in the Queue: ");
        for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    	}
    }
    return 0;
}
int main(){
    int choice=1;
    while(choice!=0){
    	printf("\nfront=%d rear=%d",front,rear);
        printf("\n1-Enqueue\t2-Dequeue\t3-Display\t0-Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            Enqueue();
        else if(choice==2)
            Dequeue();
        else if(choice==3)
            display();
        else if(choice==0)
            return 0;
        else
            printf("Enter a vaid choice.");                
    }
}
