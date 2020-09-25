#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;
};

void createNode(Node **head, int new_val) {
    //allocating new node
    Node *newNode = new Node();
    newNode->data = new_val;
    newNode->next = NULL;
    //check if this is the first node. Then insert the value here and make head point to this node
    if (*head == NULL) {
       *head = newNode;
    } else {
     // moving to the last of the nodes and inserting the value after that
        Node *curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        
        curr->next = newNode;
   }
}

void printList(Node* head) {
    Node *curr = head;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    puts("");
}

Node* removeNodeWithoutHead(Node *del_node) {
    if (del_node == NULL)   return;
    else {
        Node *temp = del_node;
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
    return del_node;
}

int main() {
    Node *head = NULL; // initially the value of the head is NULL
    createNode(&head, 1); //creating the first node

    // creating subsequent nodes
    createNode(&head, 2);
    createNode(&head, 3);
    createNode(&head, 4);
    createNode(&head, 5);
    printf("Printing the linked list\n");
    printList(head);
    return 0;
}

