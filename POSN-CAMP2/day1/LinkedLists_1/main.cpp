#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

using namespace std;

struct listNode {
	int id;
	listNode* next;

	listNode() : id(0), next(nullptr) {}
	listNode(int id) : id(id), next(nullptr) {}
	listNode(int id, listNode* next) : id(id), next(next) {}
};

int main() {
	
	map<int, bool> ids;

	listNode* head = nullptr;

	vector<string> ans;

	while (true) {
		// create variables and check command
		int cmd, id, target;
		cin >> cmd;

		// check if command is 3, if so then break the program
		if (cmd == 3) break;

		cin >> id;


		if (cmd == 1) {

			// if same id then continue to the next node
			if (ids[id]) continue;
			else ids[id] = true;

			cin >> target;
			// set new node if head is a nullptr
			if (head == nullptr) head = new listNode(id, nullptr);
			else {
				// traverse the linked list until we hit the target
				listNode* traverse = head;
				while (traverse->next != nullptr && traverse->id != target) {
					traverse = traverse->next;
				}

				// create new node
				listNode *newNode = new listNode(id);

				// check if traversal node is a nullptr
				if (traverse->next == nullptr && traverse->id != target) {
					newNode->next = head;
					head = newNode;
				} else {
					newNode->next = traverse->next;
					traverse->next = newNode;
				}
			}
		} else {

			// if no node then dont delete;
			if (head != nullptr && head->next == nullptr) {
				continue;
			}

			target = id;

			if (head != nullptr && head->id == target) {
				listNode* temp = head;
				head = head->next;
				delete temp;
			}

			listNode* traverse = head;
			while (traverse != nullptr && traverse->next != nullptr && traverse->next->id != target) {
				traverse = traverse->next;
			}

			if (traverse != nullptr && traverse->next != nullptr) {
				listNode* temp = traverse->next;
				traverse->next = temp->next;
				delete temp;
			}

			ids[target] = false;
		}

		string pb = "";

		listNode* trav = head;

		while (trav != nullptr) {
			pb += to_string(trav->id) + " ";
			trav = trav->next;
		}

		pb += '\n';

		if (!ans.empty() && pb == ans[ans.size()-1]) continue;
		else ans.push_back(pb);
	}
	
	for (auto c : ans) {
		cout << c;
	}

	return 0;
}
