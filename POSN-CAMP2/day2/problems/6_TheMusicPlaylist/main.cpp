#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

int main() {

	int n; cin >> n;
	list<string> playlist;

	string ans = "";

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "ADD") {
			string song; cin >> song;
			playlist.emplace_back(song);
			continue;
		}

		if (cmd == "REMOVE") {
			if (playlist.empty()) {
				ans += "EMPTY\n";
				continue;
			}
			ans += playlist.front() + '\n';
			playlist.pop_front();
			continue;
		}

		if (cmd == "SHOW") {
			if (playlist.empty()) {
				ans += "EMPTY\n";
				continue;
			}

			for (auto it = playlist.begin(); it != playlist.end(); ++it) {
				ans += *it;
				if (next(it) != playlist.end()) ans+= " -> ";
			}
			ans += '\n';
		}

		if (cmd == "COUNT") {
			ans += to_string(playlist.size()) + '\n';
		}
	}

	cout << ans;

	return 0;

}
