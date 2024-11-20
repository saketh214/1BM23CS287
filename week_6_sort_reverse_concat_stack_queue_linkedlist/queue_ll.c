#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

void enque(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode; 
    }
    else {
        rear->next = newnode;  
        rear = newnode;         
    }
}


int deque(){
    if(front==NULL && rear==NULL){
        printf("No elements in queue \n");
        return -1;
    }
    else {
        struct node* temp= front;
        front = front->next;
        int el = temp->data;
        free(temp);
        return el;
    }
}

void display()  
{
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *ptr = front; 
    while (ptr->next != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);  
    printf("\n");
}


int main(){
    int choise;
    printf("1. ENQUE \n 2. DEQUE\n 3. Display \n 4. exit \n");
    while(1){
        scanf("%d",&choise);
        if(choise==1){
            int num;
            printf("Enter data: ");
            scanf("%d",&num);
            enque(num);
        }
        else if(choise==2){
            int poped = deque();
            if(poped!=-1){
                printf("%d has been removed from queue \n", poped);
            }
        }
        else if(choise==3) display(front);
        else break;
    }
}
