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

void printLevelOrder(struct node *root) {
    queue<struct node*> q;
    q.push(root);

    while(q.empty() == false) {
        struct node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL) 
            q.push(curr->right);
    }
}

int main() {

    //generating tree:
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /*

        1
       / \
      2   3
     / \
    4   5

    */

    printLevelOrder(root);
    
    return 0;
}