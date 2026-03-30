#include <bits/stdc++.h>
using namespace std;

#define speedBooster ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

// dont forget to handle if farmer needs more rice than avaliable

struct cmp {
    bool operator()(const pair<long double, int>& a, const pair<long double, int>& b) {
        return a.first > b.first;
    }
};

signed main() {
    int k; cin >> k;
    priority_queue<pair<long double,int>, vector<pair<long double,int>>, greater<>> rice;
    queue<int> farmers;
    vector<double> ans;

    while (k--) {
        double p,q;
        cin >> p >> q;
        rice.push({(long double)p/q,q});
    }

    int m; cin >> m;

    while (m--) {
        int amount; cin >> amount;
        farmers.push(amount);
    }

    while (!farmers.empty() && !rice.empty()) {
        int farmer = farmers.front(); farmers.pop();
        double sum = 0;

        while (farmer > 0 && !rice.empty()) {
            auto curRice = rice.top(); rice.pop();
            if (farmer >= curRice.second) {
                sum += curRice.second * curRice.first;
                farmer -= curRice.second;
            } else {
                sum += farmer * curRice.first;
                curRice.second -= farmer;
                farmer = 0;
            }

            if (curRice.second > 0) {
                rice.push(curRice);
            }
        }

        ans.push_back(sum);

    }

    for (auto& a : ans)
        cout << fixed << setprecision(3) << a << endl;

    return 0;
}