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

void printLinkedList(struct Node* head) {
    int count = 0;
    while(head != NULL && count < 15) {
        cout << head->data << " ";
        head = head->next;
        count++;
    }
    cout << endl;
}

struct Node *slow = NULL;
struct Node *fast = NULL;

bool isLoop(struct Node *head) {
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int loopLength(struct Node *head) {
    if(isLoop(head)) {
        int count = 1;
        slow = slow->next;
        while(slow != fast) {
            slow = slow->next;
            count++;
        }
        return count;
    }
    return -1;
}

struct Node* startingPoint(struct Node *head, int loop_length) {
    struct Node *temp1 = head;
    struct Node *temp2 = head;
    while(loop_length--) {
        temp1 = temp1->next;
    }
    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

int main() {
    cout << "Singly Linked list" << endl;
    struct Node *head = newNode(10);
    slow = head;
    fast = head;
    head->next = newNode(3);
    head->next->next = newNode(7);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = head->next->next->next;
    /*
        10 -> 3 -> 7 -> 5 -> 4
    */
    printLinkedList(head);
    cout << "Linked List is ";
    if(isLoop(head)) 
        cout << "looped" << endl;
    else
        cout << "not looped" << endl;
    int loop_length = loopLength(head);
    cout << "Loop length is " << loop_length << endl;
    if (loop_length != -1)
        cout << "starting point of loop is " << startingPoint(head, loop_length)->data << endl;

    return 0;
}

