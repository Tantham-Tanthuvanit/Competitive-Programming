#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {

	string newLn;
	stack<int> duan;
	vector<int> maiDuan;

	char c;

	while (true) {
		cin >> c;
		if (c == 'S') break;
		if (c != ' ') newLn += c;
	}

	for (int i = 0; i < newLn.size(); i++) {
		if (newLn[i] == 'S' || newLn[i] == 'E') continue;
		if (newLn[i+1] == 'E') duan.push(newLn[i]-'0');
		else maiDuan.push_back(newLn[i] - '0');
	}

	vector<int> ans;
	while (!duan.empty()) {
		ans.push_back(duan.top());
		duan.pop();
	}

	for (int i : maiDuan) {
		ans.push_back(i);
	}

	for (int i : ans) {
		cout << i << ' ';
	}

}
