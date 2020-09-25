#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInOrder(struct node* root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void findLevelAverage(struct node* root) {
    queue<struct node*> q;
    q.push(root);
    int currLevel = 0;
    while(q.empty() == false) {
        int sum = 0, count = 0;
        queue<struct node*> temp;
        while(q.empty() == false) {
            struct node *currNode = q.front();
            q.pop();
            sum += currNode->data;
            count++;
            if (currNode->left != NULL)
                temp.push(currNode->left);
            if (currNode->right != NULL) 
                temp.push(currNode->right);
        }
        q = temp;
        cout << "Average of level " << currLevel << " = " << ((sum * 1.0) / count) << endl;
        currLevel++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    /*

         1          // average = 1
       /   \
      2     3       //average = 2.5
     / \   / \
    4   5 6   7     //average = 5.5


    */

    // inorder view of the original tree
    printInOrder(root);

    // printing the averages;
    printf("\nPrinting the averages of each level of the BST: \n");
    findLevelAverage(root);
    return 0;
}