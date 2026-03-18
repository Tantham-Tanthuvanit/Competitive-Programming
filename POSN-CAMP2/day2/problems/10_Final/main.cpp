#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int priority;
    Node* next;
    Node* prev;

    Node(int i, string n, int p) {
        id = i;
        name = n;
        priority = p;
        next = prev = nullptr;
    }
};

struct Action {
    string type;
    Node* node;
    int pos;
};

Node* waiting_head = nullptr;
Node* waiting_tail = nullptr;

Node* active_head = nullptr;
Node* active_tail = nullptr;

int waiting_size = 0;
int active_size = 0;

Action undo_stack[2005];
int top = -1;

void pushUndo(string type, Node* node, int pos) {
    top++;
    undo_stack[top] = {type, node, pos};
}

Action popUndo() {
    if (top == -1) return {"", nullptr, -1};
    return undo_stack[top--];
}

int main() {
    int n; cin >> n;

    while (n--) {
        string cmd; cin >> cmd;

        // ARRIVE
        if (cmd == "ARRIVE") {
            int id, priority;
            string name;
            cin >> id >> name >> priority;

            Node* node = new Node(id, name, priority);

            if (!waiting_head) {
                waiting_head = waiting_tail = node;
            } else {
                waiting_tail->next = node;
                waiting_tail = node;
            }

            waiting_size++;
            pushUndo("ARRIVE", node, -1);
        }

        // PROCESS
        else if (cmd == "PROCESS") {
            if (!waiting_head) {
                cout << "NO REQUEST\n";
                continue;
            }

            Node* node = waiting_head;
            waiting_head = waiting_head->next;
            if (!waiting_head) waiting_tail = nullptr;

            waiting_size--;

            node->next = nullptr;
            node->prev = active_tail;

            if (!active_head) {
                active_head = active_tail = node;
            } else {
                active_tail->next = node;
                active_tail = node;
            }

            active_size++;
            pushUndo("PROCESS", node, -1);
        }

        // CANCEL
        else if (cmd == "CANCEL") {
            int id; cin >> id;

            Node* cur = active_head;
            int pos = 1;

            while (cur && cur->id != id) {
                cur = cur->next;
                pos++;
            }

            if (!cur) {
                cout << "NOT FOUND\n";
                continue;
            }

            if (cur->prev) cur->prev->next = cur->next;
            else active_head = cur->next;

            if (cur->next) cur->next->prev = cur->prev;
            else active_tail = cur->prev;

            active_size--;

            cout << "CANCELLED " << id << '\n';
            pushUndo("CANCEL", cur, pos);
        }

        // FIND
        else if (cmd == "FIND") {
            int id; cin >> id;

            Node* cur = active_head;
            int pos = 1;

            while (cur) {
                if (cur->id == id) {
                    cout << "FOUND " << cur->id << " "
                         << cur->name << " "
                         << cur->priority << " "
                         << pos << '\n';
                    break;
                }
                cur = cur->next;
                pos++;
            }

            if (!cur) cout << "NOT FOUND\n";
        }

        // NEXT
        else if (cmd == "NEXT") {
            if (!waiting_head) {
                cout << "NO REQUEST\n";
            } else {
                cout << "NEXT "
                     << waiting_head->id << " "
                     << waiting_head->name << " "
                     << waiting_head->priority << '\n';
            }
        }

        // SHOW_ACTIVE
        else if (cmd == "SHOW_ACTIVE") {
            if (!active_head) {
                cout << "EMPTY\n";
                continue;
            }

            Node* cur = active_head;
            while (cur) {
                cout << "(" << cur->id << "," << cur->name << "," << cur->priority << ")";
                if (cur->next) cout << " -> ";
                cur = cur->next;
            }
            cout << '\n';
        }

        // SHOW_WAITING
        else if (cmd == "SHOW_WAITING") {
            if (!waiting_head) {
                cout << "EMPTY\n";
                continue;
            }

            Node* cur = waiting_head;
            while (cur) {
                cout << "(" << cur->id << "," << cur->name << "," << cur->priority << ")";
                if (cur->next) cout << " | ";
                cur = cur->next;
            }
            cout << '\n';
        }

        // COUNT_ACTIVE
        else if (cmd == "COUNT_ACTIVE") {
            cout << active_size << '\n';
        }

        // COUNT_WAITING
        else if (cmd == "COUNT_WAITING") {
            cout << waiting_size << '\n';
        }

        // UNDO
        else if (cmd == "UNDO") {
            Action act = popUndo();

            if (act.type == "") {
                cout << "NO ACTION\n";
                continue;
            }

            Node* node = act.node;

            // UNDO ARRIVE
            if (act.type == "ARRIVE") {
                if (waiting_head == waiting_tail) {
                    waiting_head = waiting_tail = nullptr;
                } else {
                    Node* cur = waiting_head;
                    while (cur->next != waiting_tail) {
                        cur = cur->next;
                    }
                    cur->next = nullptr;
                    waiting_tail = cur;
                }
                waiting_size--;

                cout << "UNDONE ARRIVE " << node->id << '\n';
            }

            // UNDO PROCESS
            else if (act.type == "PROCESS") {
                if (active_head == active_tail) {
                    active_head = active_tail = nullptr;
                } else {
                    active_tail = active_tail->prev;
                    active_tail->next = nullptr;
                }
                active_size--;

                node->next = waiting_head;
                node->prev = nullptr;

                if (waiting_head) waiting_head->prev = nullptr;
                waiting_head = node;

                if (!waiting_tail) waiting_tail = node;

                waiting_size++;

                cout << "UNDONE PROCESS " << node->id << '\n';
            }

            // UNDO CANCEL
            else if (act.type == "CANCEL") {
                int pos = act.pos;

                if (pos == 1) {
                    node->next = active_head;
                    node->prev = nullptr;

                    if (active_head) active_head->prev = node;
                    active_head = node;

                    if (!active_tail) active_tail = node;
                } else {
                    Node* cur = active_head;
                    for (int i = 1; i < pos - 1; i++) {
                        cur = cur->next;
                    }

                    node->next = cur->next;
                    node->prev = cur;

                    if (cur->next) cur->next->prev = node;
                    else active_tail = node;

                    cur->next = node;
                }

                active_size++;

                cout << "UNDONE CANCEL " << node->id << '\n';
            }
        }
    }

    return 0;
}
