# include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* newNode(int data, struct Node *prev=NULL, struct Node *next=NULL) {
    struct Node *n = new Node();
    n->data = data;
    n->prev = prev;
    n->next = next;
    return n;
}

void addEnd(int data, struct Node *head) {
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    struct Node *n = newNode(data, temp);
    temp->next = n;
}

struct Node* addFront(int data, struct Node *head) {
    struct Node *n = newNode(data, NULL, head);
    head->prev = n;
    return n;
}

void addAfterNthElement(int data, struct Node *head, int pos) {
    struct Node *temp = head;
    int count = 1;
    while(count != pos) {
        temp = temp->next;
        count++;
    }
    struct Node *n = newNode(data, temp, temp->next);
    temp->next->prev = n;
    temp->next = n;
}

void insertAfterEle(int data, struct Node *head, int ele) {
    struct Node *temp = head;
    while(temp->data != ele) {
        temp = temp->next;
    }
    struct Node *n = newNode(data, temp, temp->next);
    temp->next->prev = n;
    temp->next = n;
}

void insertBeforeEle(int data, struct Node *head, int ele) {
    struct Node *temp = head;
    while(temp->next && temp->next->data != ele) {
        temp = temp->next;
    }
    struct Node *n = newNode(data, temp, temp->next);
    temp->next->prev = n;
    temp->next = n;
}

void printLinkedList(struct Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printReversedLinkedList(struct Node* head) {
    while(head->next != NULL) {
        head = head->next;
    }
    while(head != NULL) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

int main() {
    cout << "Doubly Linked list" << endl;
    struct Node *head = newNode(10);
    head->next = newNode(3, head);
    head->next->prev = head;
    head->next->next = newNode(7, head->next);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(5, head->next->next);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(4, head->next->next->next);
    head->next->next->next->next->prev = head->next->next->next;
    /*
        10 <=> 3 <=> 7 <=> 5 <=> 4
    */
    printLinkedList(head);
    printReversedLinkedList(head);
    cout << "Adding 8 in end" << endl;
    addEnd(8, head);
    printLinkedList(head);
    printReversedLinkedList(head);
    cout << "Adding 1 in front" << endl;
    head = addFront(1, head);
    printLinkedList(head);
    printReversedLinkedList(head);
    cout << "Adding 3 after 4th element" << endl;
    addAfterNthElement(3, head, 4);
    printLinkedList(head);
    printReversedLinkedList(head);
    cout << "Adding 55 after element containing 3 in Linked list" << endl;
    insertAfterEle(55, head, 3);
    printLinkedList(head);
    printReversedLinkedList(head);
    cout << "Adding 22 before element containing 5 in Linked list" << endl;
    insertBeforeEle(22, head, 5);
    printLinkedList(head);
    printReversedLinkedList(head);
    return 0;
}
