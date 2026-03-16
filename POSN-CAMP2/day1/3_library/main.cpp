#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	stack<int> stck;

	string line;

	cin >> line;

	for (char c : line) {
		if (c == 'n') stck.push(1);
		else if (c == 's') {
			if (stck.empty()) {
				cout << "ERR";
				return 0;
			} else {
				stck.pop();
			}
		}
	}

	if (!stck.empty()) cout << "ERR";
	else cout << "OK";

	return 0;

}
