#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * VISIT url : push page before into stack, set current = url
 * BACK		 : if empty print no history, else current = stack.top() and then pop
 * CURRENT	 : print current
 */

int main() {

	string current = "home";
	stack<string> stck;

	int n; cin >> n;

	string ans = "";

	string cmd;
	while (n--) {
		cin >> cmd;
		if (cmd == "VISIT") {
			string url; cin >> url;
			stck.push(current);
			current = url;
			continue;
		}

		if (cmd == "BACK") {
			if (stck.empty()) {
				ans += "NO HISTORY\n";
			} else {
				current = stck.top();
				stck.pop();
				ans += current + '\n';  // ✅ ADD THIS
			}
			continue;
		}

		if (cmd == "CURRENT") {
			ans += current + '\n';
			continue;
		}
	}

	cout << ans;

	return 0;

}
