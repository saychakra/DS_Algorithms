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

// function to print the height/maximum depth of the tree
int maxHeight(struct node* root) {
    if (root == NULL)   return 0;
    else {
        // recursively find the height of the left and
        // right subtrees
        int lHeight = maxHeight(root->left);
        int rHeight = maxHeight(root->right);

        //return the larger of the two values + 1
        return max(lHeight, rHeight) + 1;
    }
}

int main() {

    struct node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(5);
    root -> left -> left -> left = newNode(7);

    //query for the height of the tree
    printf("The height of the tree: %d\n", maxHeight(root));

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

Height of the tree should be: 4

*/
