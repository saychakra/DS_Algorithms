#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
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

    queue <struct node*> q;
    stack <struct node*> s;

    q.push(root);

    while (q.empty() == false) {
        struct node *currRoot = q.front();
        q.pop();
        s.push(currRoot);
        if(currRoot -> right != NULL)
            q.push(currRoot -> right);
        if(currRoot -> left != NULL)
            q.push(currRoot -> left);
    }
    while (s.empty() == false) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}

/* the algorithm for printing the tree in inorder without recursion is as follows:

1) Create an empty queue and an empty stack
2) Enqueue the root to the queue
3) Loop while the queue is not empty:
    a) Dequeue the front element of the queue and make it the current Root 
    b) Push the current Root element into the stack
    c) Enqueue all the other children of the current Root element 
    NOTE: Right first then left
5) Pop off all the elements of the stack.

---------------------------------courtsey of GeeksforGeeks.org------------------------------------------

*/
