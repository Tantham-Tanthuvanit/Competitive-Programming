#include <cstdint>
#include <iostream>
#include <ostream>
#include <queue>
#include <string>

using namespace std;

int main() {

	int n; cin >> n;
	uint16_t count = 0;

	queue<string> guests;

	string ans = "";
	
	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "ARRIVE") {
			string name; cin >> name;

			count++;

			guests.push(name);
			continue;
		}

		if (cmd == "SERVE") {
			if (count == 0) {
				ans += "NONE\n";
				continue;
			}
			count--;
			ans += guests.front() + '\n';
			guests.pop();
			continue;
		}

		if (cmd == "COUNT") {
			ans += to_string(count) + '\n';
			continue;
		}

		if (cmd == "NEXT") {
			if (count == 0) {
				ans += "NONE\n";
				continue;
			}
			ans += guests.front() + '\n';
		}
	}

	cout << ans;

	return 0;

}
