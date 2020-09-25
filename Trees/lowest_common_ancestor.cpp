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

functions for finding out the LCA node, when 2 nodes are supplied
It is assumed that the values of n1 and n2 which are being supplied
should already be present in the BST
*/

struct node* lca(struct node *root, int n1, int n2) {
    while(root != NULL) {
        //check if n1 and n2 are smaller than the root
        // then point root to the left subtree
        if (n1 < root->data && n2 < root->data) {
            // point to the left subtree
            root = root->left;
        }

        //else check if n1 and n2 are greater than the root
        // then point root to the right subtree
        else if (n1 > root->data && n2 > root->data) {
            //point root to the right subtree
            root = root->right;
        }

        //else basically return the value (break out of the loop)
        else 
            break;
    }
    return root;
}

int main() {

    struct node *root = newNode(20);
    root -> left = newNode(8);
    root -> right = newNode(22);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(12);
    root -> left -> right -> left = newNode(10);
    root -> left -> right -> right = newNode(14);

    // calling the function to get the lca of 4 and 14
    struct node* lca_val = lca(root, 4, 14);
    printf("%d is the LCA of 4 and 14\n", lca_val->data);

    return 0;
}

/* This is the structure of the BST created.
        20
       /  \
      8    22
     / \
    4   12
       /  \
      10  14

When the two nodes are passed as n1 = 4 and n2 = 14, then 
the result should be 8. Since 8 is the lca of 4 and 14.
*/
