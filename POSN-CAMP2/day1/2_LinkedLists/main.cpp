#include <iostream>

using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int v) {
        id = v;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->id;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
}

bool exists(Node* head, int x) {
    while (head) {
        if (head->id == x) return true;
        head = head->next;
    }
    return false;
}

int length(Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

int main() {

    Node* head = nullptr;

    while (true) {
        char cmd;
        cin >> cmd;

        if (cmd == 'E') break;

        if (cmd == 'I') {
            int x, t;
            cin >> x >> t;

            if (exists(head, x)) continue;

            Node* newNode = new Node(x);

            if (!head) {
                head = newNode;
                printList(head);
                continue;
            }

            Node* cur = head;
            Node* prev = nullptr;

            while (cur && cur->id != t) {
                prev = cur;
                cur = cur->next;
            }

            if (!cur) { // insert last
                Node* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
            else { // insert before t
                if (!prev) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    prev->next = newNode;
                    newNode->next = cur;
                }
            }

            printList(head);
        }

        if (cmd == 'D') {
            int x;
            cin >> x;

            if (length(head) <= 1) continue;

            Node* cur = head;
            Node* prev = nullptr;

            while (cur && cur->id != x) {
                prev = cur;
                cur = cur->next;
            }

            if (!cur) continue;

            if (!prev) {
                head = head->next;
            } else {
                prev->next = cur->next;
            }

            delete cur;

            printList(head);
        }
    }

    return 0;
}
