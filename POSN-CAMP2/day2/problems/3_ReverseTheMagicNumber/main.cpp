#include <iostream>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;
	int cmd;
	stack<int> nums;

	while (n--) {
		cin >> cmd;
		nums.push(cmd);
	}

	while (!nums.empty()) {
		cout << nums.top() << ' ';
		nums.pop();
	}

	return 0;

}
