#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    long long T, F;
    cin >> T >> F;

    vector<pair<long long,long long>> stations(N);

    for (int i = 0; i < N; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    // sort by distance
    sort(stations.begin(), stations.end());

    priority_queue<long long> pq; // max heap

    long long curr = F;
    int i = 0;
    int stops = 0;

    while (curr < T) {
        // add reachable stations
        while (i < N && stations[i].first <= curr) {
            pq.push(stations[i].second);
            i++;
        }

        // no station to refuel
        if (pq.empty()) {
            cout << -1;
            return 0;
        }

        // refuel with largest available
        curr += pq.top();
        pq.pop();
        stops++;
    }

    cout << stops;
}
