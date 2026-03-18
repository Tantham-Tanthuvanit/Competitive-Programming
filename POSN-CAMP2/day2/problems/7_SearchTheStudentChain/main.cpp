#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

int main() {

	int n; cin >> n;
	list<int> students;

	string ans = "";

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "ADD") {
			int student; cin >> student;
			students.emplace_back(student);
			continue;
		}

		if (cmd == "PRINT") {
			if (students.empty()) {
				ans += "EMPTY\n";
				continue;
			}

			for (auto it = students.begin(); it != students.end(); ++it) {
				ans += to_string(*it);
				if (next(it) != students.end()) ans+= " ";
			}
			ans += '\n';
		}

		if (cmd == "FIND") {

			int target; cin >> target;

			list<int>::iterator it = find(students.begin(), students.end(), target);

			if (it != students.end()) {
				int pos = distance(students.begin(), it)+1;
				ans += to_string(pos) + '\n';
			} else {
				ans += "NOT FOUND\n";
			}
		}

	}

	cout << ans;

	return 0;

}
