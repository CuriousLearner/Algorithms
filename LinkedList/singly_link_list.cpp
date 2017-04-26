# include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data, struct Node* next=NULL) {
    struct Node *n = new Node();
    n->data = data;
    n->next = next;
    return n;
}

void addEnd(int data, struct Node *head) {
    struct Node *n = newNode(data);
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

struct Node* addFront(int data, struct Node *head) {
    struct Node *n = newNode(data);
    n->next = head->next;
    head = n;
    return head;
}

void addAfterNthElement(int data, struct Node *head, int pos) {
    struct Node *n = newNode(data);
    struct Node *temp = head;
    int count = 1;
    while(count != pos) {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertAfterEle(int data, struct Node *head, int ele) {
    struct Node *n = newNode(data);
    struct Node *temp = head;
    while(temp->data != ele) {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertBeforeEle(int data, struct Node *head, int ele) {
    struct Node *n = newNode(data);
    struct Node *temp = head;
    while(temp->next->data != ele) {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void printLinkedList(struct Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    cout << "Singly Linked list" << endl;
    struct Node *head = newNode(10);
    head->next = newNode(3);
    head->next->next = newNode(7);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(4);
    /*
        10 -> 3 -> 7 -> 5 -> 4
    */
    printLinkedList(head);
    cout << "Adding 8 in end" << endl;
    addEnd(8, head);
    printLinkedList(head);
    cout << "Adding 1 in front" << endl;
    head = addFront(1, head);
    printLinkedList(head);
    cout << "Adding 3 after 4th element" << endl;
    addAfterNthElement(3, head, 4);
    printLinkedList(head);
    cout << "Adding 55 after element containing 3 in Linked list" << endl;
    insertAfterEle(55, head, 3);
    printLinkedList(head);
    cout << "Adding 22 before element containing 5 in Linked list" << endl;
    insertBeforeEle(22, head, 5);
    printLinkedList(head);
    return 0;
}
