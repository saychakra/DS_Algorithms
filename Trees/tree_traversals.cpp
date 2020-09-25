#include <bits/stdc++.h>
using namespace std;


struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    //allocating memory for the new node
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printInOrder(struct node* root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root -> data);
    printInOrder(root -> right);
}

void printPreOrder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(struct node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {

    struct node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left->left = newNode(5);

    cout << "\nPrinting the tree in In Order: " << endl;
    printInOrder(root);

    cout << "\nPrinting the tree in Pre Order: " << endl;
    printPreOrder(root);

    cout << "\nPrinting the tree in Post Order: " << endl;
    printPostOrder(root);
    return 0;
}

/*
        1
       / \
      2   3
     /
    5
Inorder traversal should be: 5 2 1 3
Preorder traversal should be: 1 2 5 3
Postorder traversal should be: 5 2 3 1

*/