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
        p1->prev = *head;
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
    Node *p1, *before, *here;
    int ctr = 1;
    here = *head;
    before = NULL;

    p1 = (Node *)malloc(sizeof(Node));
    p1->value = value;
    p1->next = NULL;
    p1->prev = NULL;

    if (countNodes(*head) + 1 < pos) {
        cout << "Cannot insert!" << endl;
        return;
    }
    else {
        if (isEmpty(*head) && pos == 1) {
            *head = p1;
            p1->prev = *head;
            return;
        }
        else if (*head != NULL && pos == 1) {
            p1->next = *head;
            *head = p1;
            p1->prev = *head;
        }
        else {
            while (here->next != NULL && ctr != pos) {
                before = here;
                here = here->next;
                ++ctr;
            }
            before->next = p1;
            p1->prev = before;
            if (here->next != NULL) {
                p1->next = here->next;
                here->next->prev = p1;
            }
        }
    }
}

void deleteNode(Node **head, int value) {
    Node *before, *discard;
    discard = *head;
    before = NULL;

    if (isEmpty(*head)) {
        cout << "Cannot delete!" << endl;
        return;
    }
    else {
        if (value == discard->value) {
            if (discard->next != NULL)
                discard->next->prev = NULL;
            free(discard);
            cout << "Success!" << endl;
        }
        while (discard != NULL) {
            before = discard;
            discard = discard->next;
        }
        if (discard == NULL) {
            cout << "Cannot delete!" << endl;
            return;
        }
        else {
            before->next = discard->next;
            discard->next->prev = before;
            free(discard);
            cout << "Success!" << endl;
        }
    }
}

void locateNode(Node *head, int value) {
    Node *p1;

}


int main() {

}