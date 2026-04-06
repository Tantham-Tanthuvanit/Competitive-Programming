#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, K;
    getline(cin, S);
    getline(cin, K);

    string left = "";
    int pos = 0;
    bool insertMode = true;

    for (char c : K) {
        if (c == 'I') {
            insertMode = !insertMode;
        }
        else if (c == 'D') {
            if (pos < S.size()) pos++;
        }
        else {
            if (insertMode) {
                left += c;
            } else {
                if (pos < S.size()) {
                    left += c;
                    pos++; // overwrite
                } else {
                    left += c; // append
                }
            }
        }
    }

    // append remaining original text
    left += S.substr(pos);

    cout << left;
}
