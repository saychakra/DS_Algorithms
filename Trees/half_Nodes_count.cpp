#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

unsigned int findHalfNodes(struct node *root) {
    
    if (root == NULL)
        return 0;
    
    int count = 0;

    queue<struct node*> q;
    //pushing the root node to the queue
    q.push(root);
    while (q.empty() == false) {
        //temp node contains the root of the tree ie the front element
        struct node *temp = q.front();
        q.pop();

        //check if this temp node is a half node
        if(!temp->left && temp->right || temp->left && !temp->right)
            count++;
        
        //push the children of the temp node to the queue
        if (temp->left != NULL) 
            q.push(temp->left);
        if (temp->right != NULL) 
            q.push(temp->right);
    }
    return count;
}

int main() {

    //generating tree:
    struct node *root = createNode(2);
    root->left = createNode(7);
    root->right = createNode(5);
    root->left->right = createNode(6);
    root->left->right->left = createNode(1);
    root->left->right->right = createNode(11);
    root->right->right = createNode(9);
    root->right->right->left = createNode(4);

    /*

        2
       /  \
      7    5
       \    \
        6    9
       / \   /
      1  11 4

    here half nodes are 7, 5 and 4. Hence count on half nodes = 3.
    */

    unsigned int final_count = findHalfNodes(root);
    cout << "The number of half nodes in the tree are: " << final_count << endl;
    return 0;
}

/* the algorithm for printing the half nodes in the tree is as follows:

1) Create an empty queue q
2) If the root node is null then return 0. Obviously as the tree does ot exist!
2) Push the root node of the tree into the queue
3) Loop while the queue is not empty
    a) Pop the front element from the queue
    b) Check if the element is a half node
        b.1) If yes, increment the count variable by 1
    c) Check if the left child of the tree exists, if so, push it into the queue
    d) Check if the right child of the tree exists, if so, push it into the queue
    
----------------------------------courtsey of GeeksforGeeks.org------------------------------------------

*/