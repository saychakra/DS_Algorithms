#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node* firstNode(int data) {
  struct node* node = (struct node*) malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* insertBST(struct node *root, int key) {
    // if the tree is empty then create the first element
    if (root == NULL) return firstNode(key);

    // else start inserting according the BST logic
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);
    return root;
}

void inorder(struct node* root) {
    if (root == NULL) return;
    else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }
    // create a binary search tree based on the elements
    struct node* root = NULL;
    root = insertBST(root, arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        insertBST(root, arr[i]);
    }

    //print the inorder traversal of the BST
    printf("\nThe sorted version of the above array is: \n");
    inorder(root);
    puts("");

    // if it is required to change the original array:
    // take a return from the inorder traversal function
    // and push every data part of the node into the array
    // overwriting the existing values

    return 0;
}
