#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
    int n; cin >> n;
    vector<string> words(n);
    vector<string> ans(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    
    for (int i = 0; i < n; ++i) {
        if (words[i].size() > 10) {
            string s = "";
            s += words[i][0];
            s += to_string(words[i].size()-2);
            s += words[i][words[i].size()-1];
            ans[i] = s;
        } else {
            ans[i] = words[i];
        }
    }

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}