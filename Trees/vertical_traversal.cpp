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

void fillSet(struct node* root, unordered_set<int> &s, int hd) {
    if (!root) {
        return;
    }
    fillSet(root->left, s, hd - 1);
    s.insert(hd);
    fillSet(root->right, s, hd + 1);
}


int verticalWidth(struct node* root) {
    unordered_set<int> s;

    //the third parameter is the horizontal distance of the root. And it is 0.
    fillSet(root, s, 0);
    
    return s.size();
}

int main() {

    //generating tree:
    struct node *root = createNode(7);
    root->left = createNode(6);
    root->right = createNode(5);
    root->left->left = createNode(4);
    root->left->right = createNode(3);

    /*

        7
       / \
      6   5
     / \
    4   3

    */

   cout << "\nThe vertical width of the tree is: " << verticalWidth(root) << endl;

    return 0;
}