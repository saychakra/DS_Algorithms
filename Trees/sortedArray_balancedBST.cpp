#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void printInOrder(struct node *root) {
    if (root == NULL)
        return;

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

struct node* sortedArraytoBalancedBST(vector<int> arr, int start, int end) {
    
    // base case
    if (start > end)
        return NULL;

    // we find the middle element of the array and make it the root of the tree. We repeat this step recursively
    int mid = (start + end) / 2;
    struct node* Root = createNode(arr[mid]);

    // recursively construct the left subtree
    Root->left = sortedArraytoBalancedBST(arr, start, mid-1);

    // recursively construct the right subtree
    Root->right = sortedArraytoBalancedBST(arr, mid+1, end);

    return Root;
}

int main() {
 
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr;
    for(int i = 0; i < size; i++) {
        int x; 
        cin >> x;
        arr.push_back(x);
    }
    // the array needs to be sorted. Hence sorting the given array / in this case the vector
    cout << "Sorting the array..." << endl;
    stable_sort(arr.begin(), arr.end());

    struct node* finalRoot = sortedArraytoBalancedBST(arr, 0, arr.size());
    
    cout << "\nPrinting the inorder traversal of the balanced BST from the sorted array: " << endl;
    printInOrder(finalRoot);

    return 0;
}