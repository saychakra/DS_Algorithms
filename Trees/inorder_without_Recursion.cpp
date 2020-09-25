#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* createNode(int data) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printInOrder(struct node *root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
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


    //verifying inorder with the recursive function:
    cout << "Verifying with the recursive function: " << endl;
    printInOrder(root);
    cout << endl;

    cout << "Printing the inoder tree without recursion: " << endl;
    // creating stack for the inorder traversal
    stack<struct node*> s;
    bool finish = false;
    struct node *currNode = root;
    
    while (finish == false) {
        if (currNode != NULL) {
            s.push(currNode);
            currNode = currNode->left;
        }
        else {
            if (s.empty() == false) {
                currNode = s.top();
                cout << currNode->data << " ";
                s.pop();
                currNode = currNode->right;
            }
            else 
                finish = true;
        }
    }
    return 0;
}



/* the algorithm for printing the tree in inorder without recursion is as follows:

1) Create an empty stack
2) Initialize the current node (currNode) as the root node
3) Push the current node  to the stack and set the current node to currNode->left unitil current node is NULL
4) If current node is NULL and stack is not empty then:
    a) Pop the top item from the stack
    b) Print the popped element
    c) Go to step (3)
5) If current node is NULL and the stack is also empty then we are done.

----------------------------------courtsey of GeeksforGeeks.org------------------------------------------

*/
