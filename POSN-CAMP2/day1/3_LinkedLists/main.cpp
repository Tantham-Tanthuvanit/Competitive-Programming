#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

bool exists(Node* head, int x) {
    while (head) {
        if (head->val == x) return true;
        head = head->next;
    }
    return false;
}

void print(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
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

            if (exists(head, x)) continue;

            Node* newNode = new Node{x, nullptr};

            if (!head) {
                head = newNode;
                continue;
            }

            Node* cur = head;
            Node* prev = nullptr;

            while (cur && cur->val != y) {
                prev = cur;
                cur = cur->next;
            }

            if (!cur) { // insert last
                Node* t = head;
                while (t->next) t = t->next;
                t->next = newNode;
            }
            else { // insert before Y
                if (!prev) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    prev->next = newNode;
                    newNode->next = cur;
                }
            }
        }

        if (cmd == 'r') {

            int x;
            cin >> x;

            Node* cur = head;
            Node* prev = nullptr;

            while (cur && cur->val != x) {
                prev = cur;
                cur = cur->next;
            }

            if (!cur) continue;
            if (cur->next == nullptr) continue; // cannot delete last

            if (!prev) {
                head = head->next;
            } else {
                prev->next = cur->next;
            }

            delete cur;
        }

        if (cmd == 'p') {
            print(head);
        }
    }

    return 0;
}
