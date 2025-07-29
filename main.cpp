#include <iostream>
#include <malloc.h>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertNode(Node **head, int value) {
    Node *p1, *p2;

    p1 = (Node *)malloc(sizeof(Node));
    p1->value = value;
    p1->next = NULL;
    p1->prev = NULL;

    if (*head == NULL) {
        *head = p1;
    }
    else {
        p2 = *head;
        while (p2->next != NULL) {
            p2 = p2->next;
        }
        p2->next = p1;
        p1->prev = p2;
    }
}

int countNodes(Node *head) {
    int ctr = 0;
    Node *p = head;
    while (p != NULL) {
        p = p->next;
        ctr++;
    }
    return ctr;
}

void insertNodeWithin(Node **head, int value, int pos) {
    if (pos < 1 || countNodes(*head) + 1 < pos) {
        cout << "Cannot insert!" << endl;
        return;
    }

    Node *p1;
    int ctr;

    p1 = (Node *)malloc(sizeof(Node));
    p1->value = value;
    p1->next = NULL;
    p1->prev = NULL;


    if (pos == 1) {
        p1->next = *head;
        if (*head != NULL)
            (*head)->prev = p1;
        *head = p1;
    } else {
        Node *p = *head;
        ctr = 1;
        while (ctr < pos - 1 && p != NULL) {
            p = p->next;
            ctr++;
        }

        p1->next = p->next;
        p1->prev = p;

        if (p->next != NULL)
            p->next->prev = p1;
        p->next = p1;
    }
}

void deleteNode(Node **head, int value) {
    if (isEmpty(*head)) {
        cout << "Cannot delete!" << endl;
        return;
    }

    Node *p = *head;

    while (p != NULL && p->value != value)
        p = p->next;

    if (p == NULL) {
        cout << "Cannot delete!" << endl;
        return;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        *head = p->next; // Update head if we’re deleting the first node

    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    cout << "Success!" << endl;
}

void locateNode(Node *head, int value) {
    Node *p1;

    p1 = head;
    int ctr = 0;

    while (p1 != NULL && p1->value != value) {
        p1 = p1->next;
        ctr++;
    }
    if (p1 == NULL) {
        cout << "Item not found!" << endl;
        return;
    }
    else {
        cout << "Item found!" << endl;
        cout << "Value found: " << p1->value << endl;
        cout << "Location: " << ctr << endl;
    }

}


int main() {

}