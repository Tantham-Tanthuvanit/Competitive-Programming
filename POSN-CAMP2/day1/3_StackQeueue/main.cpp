#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {

	stack<int> stck;

	int count = 1;

	char c;
	while (cin >> c) {

		if (c == '(') {
			stck.push(count);
			cout << count << ' ';
			count++;
		}
		if (c == ')') {
			cout << stck.top() << ' ';
			stck.pop();
		}

	}

	return 0;

}
