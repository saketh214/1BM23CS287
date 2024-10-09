#include<stdio.h>
int size=5;
int stack[5];
int top=-1;

void push(int val){
    if(top==size-1){
        printf("Stack overflow \n");
        return;
    }
    top++;
    stack[top]=val;
    printf("Added element to stack \n");
}

void pop(){
    if(top==-1){
        printf("stack undeflow \n");
        return;
    }
    int temp = stack[top];
    top--;
    printf("%d has been popped from stack \n", temp);
}

void display(){
    if(top==-1){
        printf("No elements to display \n");
        return;
    }
    int temp =top;
    printf("elements in stack are: \n");
    while(temp>=0){
        printf("%d \n", stack[temp]);
        temp--;
    }
}

void main(){
    int choise;
    while(1){
        printf("------------------\n\n");
        printf("Enter your choise \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display stack elements \n");
        printf("Any other to exit \n");

        scanf("%d",&choise);
        int val;
        if(choise==1){
            printf("Enter value to push \n");
            scanf("%d",&val);
            push(val);
        }
        else if(choise==2){
            pop();
        }
        else if(choise==3){
            display();
        }
        else{
            break;
        }
    }
}
