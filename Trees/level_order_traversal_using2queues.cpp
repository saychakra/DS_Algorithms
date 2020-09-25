#include <bits/stdc++.h>
using namespace std;


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printLevelOrder(struct node* root) {
    queue<struct node *> q1;
    queue<struct node *> q2;

    if (root == NULL)
        return;
    
    q1.push(root);

    while(q1.empty() == false and q2.empty() == false) {
        while(q1.empty() == false) {
            if(q1.front() -> left != NULL) 
                q2.push(q1.front() -> left);

            if (q1.front() -> right != NULL) 
                q2.push(q2.front() -> right);

            cout << q1.front()->data << " ";
            q1.pop();
        }
        cout << endl;

        while(q2.empty() == false) {
            if (q2.front() -> left != NULL) 
                q1.push(q2.front() -> left);
            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);
            cout << q2.front() -> data << " ";
            q2.pop();
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    return 0;
}