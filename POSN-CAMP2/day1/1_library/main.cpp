#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> urgent;
    vector<int> normal;

    int last = -1;

    while (true) {
        string s;
        cin >> s;

        if (s == "S") break;

        if (s == "E") {
            urgent.push(last);
        } else {
            last = stoi(s);
            normal.push_back(last);
        }
    }

    while (!urgent.empty()) {
        cout << urgent.top() << " ";
        urgent.pop();
    }

    for (int x : normal)
        cout << x << " ";
}
