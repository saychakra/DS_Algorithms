#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBegin(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    if(!head) 
        head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
    }
    
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void insertPos(int position, int value) {
    if (position == 1) {
        insertBegin(value);
    }
    else {
        int i=1;
        struct node *curr = head;
        while(i < position-1) {
            curr = curr->next;
            i++;
        }
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deletePos(int position) {
    int i = 0;
    if(!head)
        cout << "\nList is empty" << endl;
    if (position == 0) {
        head = head->next;
    }
    else {
        struct node *curr = head;
        while (i < position-1) {
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
    }
}
void displayList() {
    if(!head)
        cout << "\nThe list is empty" << endl;
    struct node *curr = head;
    while(curr->next != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << curr->data << endl;
}

void getMiddle(struct node *head) {
    int count = 0;
    struct node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    curr = head;
    int counter = 0;
    int middle_position = count / 2;
    while (counter < middle_position) {
        curr = curr->next;
        counter++;
    }
    cout << "Middle element in the list: " << curr->data << endl;
}

void reveseList() {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {

    int choice, value, position;
    cout << "\n<1> Insert value at the beginning of the list";
    cout << "\n<2> Insert value at the end of the list";
    cout << "\n<3> Insert at a particular postition (from the front)";
    cout << "\n<4> Delete at a particular position (from the front)";
    cout << "\n<5> Reverse the list";
    cout << "\n<6> Display the list";
    cout << "\n<7> Find the middle element";
    cout << "\n<0> EXIT\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nEnter the value: ";
                cin >> value;
                insertBegin(value);
                break;
            case 2:
                cout << "\nEnter the value: ";
                cin >> value;
                insertEnd(value);
                break;
            case 3:
                cout << "\nEnter the position where you wish to enter (from the front): ";
                cin >> position;
                cout << "\nEnter the value: ";
                cin >> value;
                insertPos(position, value);
                break;
            case 4: 
                cout << "\nEnter the position which you wish to delete (from the front): ";
                cin >> position;
                deletePos(position);
                break;
            case 5: 
                reveseList();
                break;
            case 6:
                displayList();
                break;
            case 7: getMiddle(head);
                    break;
            case 0: 
                exit(1);
            default:
                cout << "Wrong choice\n";
                break;
        }
    }
    return 0;
}