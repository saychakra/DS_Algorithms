#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insertBegin(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;

    if (! head) {
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
}

void insertEnd(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
    } else {
        struct node *curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
}

void insertPos(int position, int value) {
    if (position == 1) {
        insertBegin(value);
    } else {
        int i = 1;
        struct node *curr = head;
        while (i < position - 1) {
            curr = curr->next;
            i++;
        }
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
    }
}

void deletePos(int position) {
    int i = 1;
    if (!head)
        cout << "\nList is empty" << endl;
    if (position == 0) {
        head = head->next;
    } else {
        struct node *curr = head;
        while (i < position - 1)
        {
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
        curr->next->prev = curr;
    }
}

void displayList() {
    if (!head)
        cout << "\nThe list is empty" << endl;
    struct node *curr = head;
    while (curr->next != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << curr->data << endl;
}

int main() {
    int choice, value, position;
    cout << "\n<1> Insert value at the beginning of the list";
    cout << "\n<2> Insert value at the end of the list";
    cout << "\n<3> Insert at a particular postition";
    cout << "\n<4> Delete at a particular position";
    cout << "\n<5> Display the list";
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
                displayList();
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