#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL); 

int main() {

    ULTRA

    queue<string> names;

    int n;
    string cmd = "";
    cin >> n;

	string ans = "";

    while (n--) {
        cin >> cmd;
        if (cmd == "ENQUEUE") {
            string name;
            cin >> name;
            names.push(name);
            continue;
        }

        if (cmd == "DEQUEUE") {
            if (names.empty()) {
				ans += "EMPTY\n";
                continue;
            }
			ans += names.front() + '\n';
            names.pop();
            continue;
        }

        if (cmd == "FRONT") {
            if (names.empty()) {
				ans += "EMPTY\n";
                continue;
            }
			ans += names.front() + '\n';
        }
    }

	cout << ans;

    return 0;

}
