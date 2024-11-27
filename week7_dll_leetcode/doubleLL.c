#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

struct node *create_DLL (struct node*);
void display (struct node *);
struct node *insert_before(struct node *);
int delete_node (struct node *);

int main(){
    int choise;
    printf("1.Create DLL \n2.Insert to left \n3. Delete Node\n4. Display\n5.Exit\n");
    
    while(1){
        printf("Enter choise: ");
        scanf("%d",&choise);
        if(choise==1) start = create_DLL(start);
        else if(choise==2) start = insert_before(start);
        else if (choise==3) {
            int ans = delete_node(start);
            if(ans!=-1){
                printf("%d deleted from LL \n",ans);
            }
        }
        else if(choise==4) display(start);
        else if(choise==5) break;
    }
}
struct node *create_DLL (struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf ("\n enter -1 to end") ;
    printf ("\n enter the data:") ;
    scanf ("%d", &num);
    while (num != -1)
    {
        new_node=(struct node*) malloc (sizeof (struct node) ) ;
        new_node->data=num;
        if(start == NULL)
        {
            new_node->next=NULL;
            new_node->prev=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while (ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("\n enter the data:") ;
        scanf ("%d", &num) ;
    }
    return start;

}

struct node *insert_before(struct node *start) {
    int num, value;
    printf("Enter Number to insert Before\n");
    scanf("%d", &num);
    printf("Enter value to insert\n");
    scanf("%d", &value);

    struct node *ptr = start;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found\n");
        free(new_node);
        return start;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return start;
}

int delete_node (struct node *start){
    int val;
    printf("Enter value to delete\n");
    scanf("%d",&val);
    struct node *ptr = start;

    if(ptr->data == val)
    {
        struct node* temp = start; 
        start= start->next;
        int num = temp->data;
        free(temp);
        return num;
    }
    else{
        while(ptr->data!=val && ptr!=NULL){
            ptr = ptr->next;
        }
        if(ptr==NULL){
            printf("Node not found \n");
            return -1;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        int num = ptr->data;
        free(ptr);
        return num;
    }
    
}
void display (struct node *start)
{

    struct node *ptr;
    ptr=start;
    while (ptr != NULL)
    {
        printf("\t %d",ptr->data) ;
        ptr=ptr->next;
    }
    printf("\n");
}
