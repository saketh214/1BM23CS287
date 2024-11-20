#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top, *top1;

void push(int num){
    if(top==NULL){
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        top = newnode;
        
    }
    else {
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = top;
        top=newnode;

        
    }
}

int pop (){
    top1 = top;
    if(top==NULL){
        printf("Stack Underflow \n");
        return -1;
    }
    else {
        top1= top;
        top=top->next;
        int data = top1->data;
        free(top1);

        return data;

    }
}
void display ()
{
    if(top==NULL){
        printf("Stack Underflow \n");
        return;                                                           
    }

    struct node *ptr;
    ptr=top;
    while (ptr->next != NULL)
    {
    printf("%d -> ",ptr->data) ;
    ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}
int main(){
    int choise;
    printf("1. Push element to stack \n 2. Pop element\n 3. Display \n 4. exit \n");
    while(1){
        scanf("%d",&choise);
        if(choise==1){
            int num;
            printf("Enter data: ");
            scanf("%d",&num);
            push(num);
        }
        else if(choise==2){
            int poped = pop();
            if(poped!=-1){
                printf("%d has been popped from stack \n", poped);
            }
        }
        else if(choise==3) display(top);
        else break;
    }
}
