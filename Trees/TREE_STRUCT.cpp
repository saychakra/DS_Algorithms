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


/*

functions for performing the operations are to be written here

*/

int main() {

    struct node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(5);
    root -> left -> left -> left = newNode(7);

    // operations required are to be done here

    return 0;
}

/*
        1
       / \
      2   3
     /
    5
   /
  7

*/
