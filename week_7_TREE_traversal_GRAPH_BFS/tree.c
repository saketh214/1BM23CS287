#include <stdio.h>
#include <malloc.h>

typedef struct BST {
    int data;
    struct BST *left;
    struct BST *right;
} node;


node* create(int value) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}


node* insert(node *root, int value) {
    if (root == NULL)
        return create(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


void preOrder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


void postOrder(node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node* root = NULL;
    int choice, value;

    printf("Binary Search Tree Operations:\n");
    printf("1. Insert element into the BST\n");
    printf("2. Display In-order traversal\n");
    printf("3. Display Pre-order traversal\n");
    printf("4. Display Post-order traversal\n");
    printf("5. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
