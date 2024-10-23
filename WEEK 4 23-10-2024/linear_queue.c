#include <stdio.h>
#define MAX 3

int que[MAX];
int front =-1, rear=-1;
void insert_element();
void display();
int delete_element();

int main(){
    int  choice;
    while(1){
        printf("\n \n ***Enter  your choice*** \n");
        printf("1.  Insert Element \n 2.  Delete Element \n 3. Display \n 4. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_element();
                    break;
            case 2: {
                        int val = delete_element();
                        if(val != -1)
                        {
                            printf("\n Deleted Element is %d \n",val);
                        }
                        break;
                    }
            case 3: display();
                    break;
            case 4: printf("Exiting.....");
                    break;

        }
        if(choice==4){
            break;
        }



    }
    return 0;

}

void insert_element(){
    if(rear== MAX-1){
        printf("QUEUE OVERFLOW \n");
        return;
    }
    int n;
    printf("Enter the element to be inserted \n");
    scanf("%d",&n);

    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else rear++;
    que[rear]=n;
    printf("element inserted ");
    return;
}

int delete_element(){
    if(front==-1 || front>rear){
        printf("QUEUE UNDERFLOW \n");
        return -1;
    }
    else{
        int val = que[front];
        front++;
        if(front>rear){
            front=-1;
            rear=-1;

        }
        return val;
    }
}

void display(){
    if(front==-1  && rear==-1){
        printf("No elements to display \n");
        return;
    }
    int i;
    for(i=front; i<=rear; i++){
        printf("%d \t",que[i]);
    }
    printf("\n");
    return;
}
