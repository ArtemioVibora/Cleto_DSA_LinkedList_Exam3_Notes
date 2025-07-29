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
        *head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    cout << "Success!" << endl;
}

void locateNode(Node *head, int value) {
    if (isEmpty(head)) {
        cout << "Cannot locate!" << endl;
        cout << "Nothing to locate!" << endl;
        cout << endl;
        return;
    }
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

void printList(Node *head) {
    if (isEmpty(head)) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *p = head;

    cout << endl;
    cout << "Printing List:" << endl;
    while (p != NULL) {


        if (p->next == NULL) {
            cout << p->value;
        }
        else {
            cout << p->value << " => ";
        }
        p = p->next;
    }
    cout << endl;
}

//Run Program
void mainMenu(int num) {
    cout << "===============================================" << endl;
    cout << "         Le Linked List Double Trouble         " << endl;
    cout << "================================================" << endl;
    cout << "Total number of nodes: " << num << endl;
    cout << "<1> Insert From the Rear" << endl;
    cout << "<2> Insert Within" << endl;
    cout << "<3> Delete Node" << endl;
    cout << "<4> Locate Node" << endl;
    cout << "<5> Print List" << endl;
    cout << "<6> Exit" << endl;
    cout << "<7> LE PLAYGROUND HARD CODE SHIT" << endl;
    cout << "------------------------------------------------" << endl;
    cout << ">>>> ";
}

//Le Playground and testing area
void hardCode() {
    cout << "Hello World!" << endl;
}

void runProgram() {
    Node *head = NULL;
    int choice;
    int data;
    int pos;
    int ctr;
    bool flag = true;

    while (flag) {
        ctr = countNodes(head);
        mainMenu(ctr);
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Insert Data: ";
                cin >> data;
                insertNode(&head, data);
                break;
            case 2:
                cout << "Insert Data: ";
                cin >> data;
                cout << "Insert Position: ";
                cin >> pos;
                insertNodeWithin(&head, data, pos);
                break;
            case 3:
                cout << "Delete Data: ";
                cin >> data;
                deleteNode(&head, data);
                break;
            case 4:
                cout << "Locate Data: ";
                cin >> data;
                locateNode(head, data);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                flag = false;
                break;
            case 7:
                hardCode();
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

    }

}
// main
int main() {
    runProgram();
}

