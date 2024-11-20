#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;

struct node* create_ll (struct node*) ;
struct node *display (struct node *);
struct node* sort(struct node*);
struct node* reverse_ll(struct node*);
struct node* concat(struct node* start1, struct node* start2);

int main(){
      start1 = create_ll(start1);
      
      printf("Linked List 1: \n");
      display(start1);

      start2 = create_ll(start2);
      printf("Linked List 2: \n");
      display(start2);

      printf("Linked list 1 (sorted): \n");
      start1 = sort(start1);
      display(start1);

      printf("Linked list 1 (reversed): \n");
      start1 = reverse_ll(start1);
      display(start1);

      printf("Linked list 1 and 2 after concatenation \n");
      start1 = concat(start1, start2);
      display(start1);
    

   return 0;
}
struct node *create_ll (struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf ("\n enter -1 to end") ;
    printf ("\n enter the data:") ;
    scanf ("%d", &num);
    while (num !=- 1)
    {
        new_node=(struct node*) malloc (sizeof (struct node) ) ;
        new_node->data=num;
        if(start == NULL)
        {
        new_node->next=NULL;
        start=new_node;
        }

        else
        {
        ptr=start;
        while (ptr->next != NULL)
        ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
        }
        printf("\n enter the data:") ;
        scanf ("%d", &num) ;
    }
    return start;

}
struct node *display (struct node *start)
{

    struct node *ptr;
    ptr=start;
    while (ptr->next != NULL)
    {
    printf("%d -> ",ptr->data) ;
    ptr=ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
    return start;

}


struct node* sort(struct node* start){
    struct node *ptr,*postptr;
    int temp;
    ptr=start;
    while(ptr->next!=NULL){
        postptr=ptr->next;
        while(postptr!=NULL){
            if(ptr->data>postptr->data){
                temp=ptr->data;
                ptr->data=postptr->data;
                postptr->data=temp;
                
            }
        postptr=postptr->next;
        }
        ptr=ptr->next;
    }
    
return start;    
}
struct node* reverse_ll(struct node* start){
if(start==NULL){
            return start;
        }
        struct node* temp = start;
        struct node* prev=NULL;
        while(temp!=NULL){
            struct node* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
            
        }
        return prev;                                                                           
}

struct node* concat(struct node* start1, struct node* start2){
    if(start1==NULL){
        return start2;
    }
    else if(start2==NULL){
        return start1;
    }

    struct node* ptr = start1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    ptr->next = start2;


    return start1;
}
