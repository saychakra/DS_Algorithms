#include <bits/stdc++.h>
using namespace std;


struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node * Node = (struct node*)malloc(sizeof(struct node));

    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    
    return Node;
}

void printInOrder(struct node *root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void modifyBSTUtil(struct node *root, int *sum) {
    if (root == NULL)
        return;
    
    // we need a revese inorder traversal and duing that
    // we need to alter the value of each of the nodes

    // recur on the right subtree
    modifyBSTUtil(root->right, sum);

    // now we have the final right sum value in the *sum variable
    // lets update the value of the corresponding nodes
    *sum += root->data;
    root->data = *sum;

    //recur on the left subtree
    modifyBSTUtil(root->left, sum);
}

void modifyBST(struct node * root) {
    int sum = 0;
    modifyBSTUtil(root, &sum);
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    struct node*root = newNode(11);
    root->right = newNode(29);
    root->left = newNode(2);
    root->right->right = newNode(40);
    root->left->right = newNode(7);
    root->left->left = newNode(1);

    //the normal inorder traversal is as follows:
    printf("\n Original inorder view of the BST: \n");
    printInOrder(root);
    
    // modifying the BST
    modifyBST(root);

    // printing the inorder traversal of the tree to observe the updated value
    printf("\n Printing the Inorder traversal of the tree after updation of the BST: \n");
    printInOrder(root);

    return 0;
}