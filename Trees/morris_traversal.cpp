#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void morris_InOrder(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        // if the left is NULL, then print the current and move towards right
        if (current->left == NULL) {
            printf("%d, ", current->data);
            current = current->right;
        }
        // else when the left is not null
        else {
            // find the predecessor
            struct node* pred = current->left;
            // to find the predecessor, keep going right, until the right node is not NULL, or the right node points back to current
            while (pred->right != NULL && pred->right != current) {
                pred = pred->right;
            }
            // now there are the two conditions:
            // if the right node is null ie when pred->rigth == NULL
            if (pred->right == NULL) {
                // establish the link with current and move left
                pred->right = current;
                // then move current towards the left
                current = current->left;
            }
            // else the condition where the left node is already visited ie pred->right == current
            // in this case go to the right node after visiting the current node and remove the link
            else {
                pred->right = NULL;
                printf("%d, ", current->data);
                current = current->right;
            }
        }
    }
}


void morris_PreOrder(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d, ", current->data);
            current = current->right;
        }
        else { 
            // finding the predecessor'
            struct node* pred = current->left;
            while (pred->right != NULL && pred->right != current) {
                pred = pred->right;
            }
            if (pred->right == NULL) {
                pred->right = current;
                // this is the main change from inorder: 
                printf("%d, ", current->data);
                current = current->left;
            }
            else {
                pred->right = NULL;
                current = current->right;
            }
        }
    }
}

void printInOrder(struct node* root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d, ", root->data);
    printInOrder(root->right);
}

void printPreOrder(struct node* root) {
    if (root == NULL) 
        return;
    printf("%d, ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    struct node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(30);
    root->left->left = createNode(-2);
    root->left->left->right = createNode(2);
    root->left->left->right->left = createNode(-1);
    root->left->right = createNode(6);
    root->left->right->right = createNode(8);
    root->right->right = createNode(40);
    // verification of the actual inorder traversal using normal recursion
    cout << "\nPrinting the inorder traversal using normal recursion: " << endl;
    printInOrder(root);
    cout << "\nPrinting the inorder traversal using morris algorithm: " << endl;
    morris_InOrder(root);

    cout << "\n\n Printing the preorder traversal of the tree using recursion: " << endl;
    printPreOrder(root);
    cout << "\nPrinting the preorder traversal using morris algorithm: " << endl;
    morris_PreOrder(root);
    return 0;
}