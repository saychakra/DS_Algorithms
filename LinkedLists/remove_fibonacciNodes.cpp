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

//function to find the length of the linked list
int ll_length(Node *head) {
    int len = 0;
    Node *curr = head;
    while(curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

//function to delete a node from the linked list
void deletePos(Node **head, int pos) {
   Node *curr = *head;
   int counter = 1;
   
   if (pos > ll_length(*head)) {
        printf("Position out of bound");
        puts("");
        return;
    }
   else {
        // moving the pointer to the mentioned position
        while(counter < pos-1) {
            curr = curr->next;
            counter++;
        }
        if (*head == NULL)   curr->next = NULL;
        else if (curr->next->next == NULL) curr->next = NULL;
        else                 curr->next = curr->next->next;   
    }
}

//function to create a fibonacci sequence upto n values. It will return a vector of fibonacci positions which needs to be deleted
vector<int> generateFiboSeries(int n) {
    vector<int> fiboSeries;
    int a = 0, b = 1, i = 3;
    fiboSeries.push_back(a);
    fiboSeries.push_back(b);
    while (i <= n) {
        int c = a+b;
        fiboSeries.push_back(c);
        a = b;
        b = c;
        i++;
    }
    return fiboSeries;
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
    
    // finding the length of the linked list to generate the fibonacci sequence upto that value
    printf("The length of the given linked list: %d\n", ll_length(head));
    int ll_len = ll_length(head);
    vector<int> fibList = generateFiboSeries(ll_len);
    //printf("Fibonacci Sequence: ");
    //for(int i : fibList)        cout << i << " ";
    //printf("\nTesting deletion of value at position 2: \n");
    //deletePos(&head, 8);
    //printList(head);

    // now we just need to run a loop for the fibonacci list and delete all the values at the corresponding positions
    for (int i : fibList) {
        deletePos(&head, i);
    }
    printList(head);
    return 0;
}
