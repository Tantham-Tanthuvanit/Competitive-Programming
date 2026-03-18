#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <type_traits>

using namespace std;

int main() {

	int n; cin >> n;
	string ans = "";

	while (n--) {
		string x;
		cin >> x;

		stack<char> stck;
		bool ok = true;

		for (char c : x) {

			if (c == '('|| c == '{' || c == '[') stck.push(c);
			else {
				if (stck.empty()) {
					ok = false;
					break;
				}

				char top = stck.top();
				stck.pop();

				if ((c == ')' && top != '(') ||
					(c == '}' && top != '{') ||
					(c == ']' && top != '[')) {
					ok = false;
					break;
				}
			}
			

		}

		if (ok && stck.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;

}
