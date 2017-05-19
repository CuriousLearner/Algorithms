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
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int findLength(struct Node *head) {
    int length = 0;
    while(head != NULL) {
        head = head->next;
        length++;
    }
    return length;
}

struct Node * findMergePoint(struct Node *head1, struct Node *head2) {
    struct Node *big_list, *small_list;
    int result;
    int length1 = findLength(head1);
    int length2 = findLength(head2);
    if (length1 > length2) {
        result = length1 - length2;
        big_list = head1;
        small_list = head2;
    }
    else {
        result = length2 - length1;
        big_list = head2;
        small_list = head1;
    }

    while(result--) {
        big_list = big_list->next;
    }

    while(big_list != NULL) {
        if (big_list == small_list)
            return big_list;
        big_list = big_list->next;
        small_list = small_list->next;
    }
    return NULL;
}


int main() {
    cout << "Singly Linked list" << endl;
    struct Node *head1 = newNode(10);
    head1->next = newNode(3);
    head1->next->next = newNode(7);
    head1->next->next->next = newNode(5);
    head1->next->next->next->next = newNode(4);
    /*
        10 -> 3 -> 7 -> 5 -> 4
    */
    printLinkedList(head1);

    struct Node *head2 = newNode(6);
    head2->next = newNode(2);
    head2->next->next = newNode(9);
    head2->next->next->next = newNode(8);
    head2->next->next->next->next = newNode(1);
    /*
        6 -> 2 -> 9 -> 8 -> 1
    */

    head2->next->next->next->next->next = head1->next->next;
    /*
        6 -> 2 -> 9 -> 8 -> 1 -> 7 ->  5 ->  4
                        10 -> 3 /
    */

    printLinkedList(head2);
    if (findMergePoint(head1, head2))
        cout << "Merge point is " << findMergePoint(head1, head2)->data << endl;
    else
        cout << "No merge point";
    return 0;
}

