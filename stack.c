#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
int push(struct Stack* stack)

{
    if (isFull(stack)){
    	printf("Stack is full.");
        return 0;
    }
    int item;
    printf("Enter the value: ");
    scanf("%d",&item);
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    printf("poped element: %d\n",stack->array[stack->top--]);
}

int display(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    else{
    	int i,max=stack->top;
    	for(i=0;i<=max;i++)
    printf("%d ",stack->array[i]);
	}
	return 0;
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    printf("Top element: %d",stack->array[stack->top]);
}

int main()
{
    printf("Enter the size of stack to be created: ");
    int size;
    scanf("%d",&size);
    struct Stack* stack = createStack(size);
    int choice=1;
    while(choice){
  	printf("\n0-exit\t1-push\t2-pop\t3-peek\t4-display\t5-No of elements in stack\t6-Destroy stack\nEnter your choice: ");
	  scanf("%d",&choice);
    if(choice==0)
        exit(2);  
  	else if(choice==1)
  		push(stack);
	else if(choice==2)
        pop(stack);
	else if(choice==3)
	    peek(stack);
	else if (choice==4)
	    display(stack);
	else if(choice==5){
        printf("No of elements in the stack are: %d",stack->top+1);
    }
    else if(choice==6){
        if (isEmpty(stack)){
            printf("Stack is empty.");
        }else{
            free(stack);
            printf("Stack destroyed.\nEnter Y to create new stack else N: ");
            char user_choice;
            scanf("%s",&user_choice);
            if(user_choice=='Y' || user_choice=='y'){
                printf("Enter the size of stack to be created: ");
                scanf("%d",&size);
                struct Stack* stack = createStack(size);
            }else{
                exit(3);
            }
        }
    }
	else
	  printf("Enter a valid choice.");
	  
	}
    return 0;
}
