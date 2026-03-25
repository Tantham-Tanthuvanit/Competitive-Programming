#include <bits/stdc++.h>
using namespace std;

int n = 0, k = 0;
vector<int> ans;
vector<bool> used(n);
int cnt = 0;

void bt() {
    if (ans.size() == k) {
        for (int x : ans) cout << x+1 << ' ';
        cout << '\n';
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        used[i] = true;
        ans.push_back(i);

        bt();

        ans.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> n >> k;
    used.assign(n, false);
	bt();
	
	cout << cnt;
}
