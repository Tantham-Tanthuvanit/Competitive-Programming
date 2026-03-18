#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

bool exists(Node* head, int x) {
    while (head) {
        if (head->val == x) return true;
        head = head->next;
    }
    return false;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void insertNode(Node*& head, int x, int y) {

    if (exists(head, x)) return;

    Node* newNode = new Node(x);

    if (!head) {
        head = newNode;
        return;
    }

    Node* cur = head;
    Node* prev = nullptr;

    while (cur && cur->val != y) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur) { // insert last
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    else { // insert before Y
        if (!prev) {
            newNode->next = head;
            head = newNode;
        }
        else {
            prev->next = newNode;
            newNode->next = cur;
        }
    }
}

void deleteIndex(Node*& head, int idx) {

    if (!head) return;

    if (idx == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    Node* prev = nullptr;
    int i = 0;

    while (cur && i < idx) {
        prev = cur;
        cur = cur->next;
        i++;
    }

    if (!cur) return;

    prev->next = cur->next;
    delete cur;
}

int main() {

    Node* head = nullptr;

    while (true) {

        char cmd;
        cin >> cmd;

        if (cmd == 'e') break;

        if (cmd == 'a') {
            int x, y;
            cin >> x >> y;
            insertNode(head, x, y);
        }

        if (cmd == 'r') {
            int i;
            cin >> i;
            deleteIndex(head, i);
        }

        if (cmd == 'p') {
            if (head) printList(head);
        }
    }

    return 0;
}
