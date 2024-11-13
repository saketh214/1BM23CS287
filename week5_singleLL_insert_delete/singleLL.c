#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node* create_ll (struct node*) ;
struct node* display (struct node *) ;
struct node* insert_beg (struct node*) ;
struct node* insert_end (struct node*) ;
struct node* insert_pos (struct node*) ;
struct node *delete_beg (struct node*);
struct node *delete_end (struct node*);
struct node *delete_node (struct node *);

int main(){
      int choice;
      printf("1:create linked list \n 2:insertbegin \n 3:insertend \n 4:insert position \n 5:display\n 6. delete beg \n 7. delete end \n 8. delete node \n 9. exit \n");
    do{
    
    printf("enter choice:\t");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            start=create_ll(start);
            break;
        case 2:
            start=insert_beg(start);
            break;
        case 3:
             start=insert_end(start);
             break;
        case 4:
            start=insert_pos(start);
            break;
       
        case 5:
            start=display(start);
            break;
        case 6:
            start=delete_beg(start);
            break;
        case 7:
            start=delete_end(start);
            break;
        case 8: 
            start=delete_node(start);
            break;

           
    }
   
    }while(choice!=9);
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
struct node *insert_beg (struct node *start)
{
    struct node *new_node;
    int num;
    printf ("\nenter the data:") ;
    scanf ("%d", &num) ;
    new_node=(struct node*) malloc (sizeof (struct node) ) ;
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}
struct node *insert_end (struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nenter the data:") ;
    scanf ("%d", &num) ;
    new_node=(struct node*) malloc (sizeof(struct node) ) ;
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    if(start == NULL)
    {
        start=new_node;
    }
    else

    while (ptr->next != NULL)
    ptr=ptr->next;
    ptr->next=new_node;
    return start;
}
struct node *insert_pos (struct node *start)
{
   int pos,num;
   printf("Enter position to insert \n");
   scanf("%d",&pos);
   printf("Enter data \n");
   scanf("%d",&num);

   int count =0;
   struct node *ptr, *prevptr;
   ptr=start;
   if(pos==0){
    struct node *new_node=(struct node*) malloc (sizeof(struct node) ) ;
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
   }
   else{
    while(ptr!=NULL){
        if(count==pos){
            struct node *new_node=(struct node*) malloc (sizeof(struct node) ) ;
            new_node->data=num;
            prevptr->next=new_node;
            new_node->next=ptr;
            break;
        }
        else{
            count++;
            prevptr=ptr;
            ptr=ptr->next;
        }
    }
    if(ptr==NULL){
        printf("Position not found \n");
        
    }
    else printf("element inserted \n");

    return start;
   }

   
}

struct node *display (struct node *start)
{

    struct node *ptr;
    ptr=start;
    while (ptr != NULL)
    {
    printf("\t %d",ptr->data) ;
    ptr=ptr->next;
    }
    printf("\n");
    return start;

}

struct node *delete_beg (struct node *start)
{
struct node *ptr;
ptr=start;
start=start->next;
free (ptr) ;
return start;
}
struct node *delete_end (struct node *start)
{

struct node *ptr, *preptr;
ptr=start;
while (ptr->next != NULL)
{

preptr=ptr;
ptr=ptr->next;
}
preptr->next=NULL;
free (ptr) ;
return start;

}
struct node *delete_node (struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\nenter the value to be deleted:") ;
scanf ("%d", &val) ;
ptr=start;
if(ptr->data == val)
{
start=delete_beg (start) ;
return start;
}
else{
while (ptr->data != val)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=ptr->next;
free (ptr) ;
return start;

}
}


