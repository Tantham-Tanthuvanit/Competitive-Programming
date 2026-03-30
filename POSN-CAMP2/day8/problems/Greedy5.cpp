#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> cities = {'A','B','C','D','E'};
    map<char,int> idx;

    for (int i = 0; i < 5; i++)
        idx[cities[i]] = i;

    int dist[5][5] = {
        {0,20,42,35,40},
        {20,0,30,34,25},
        {42,30,0,12,70},
        {35,34,12,0,21},
        {40,25,70,21,0}
    };

    char start;
    cin >> start;

    vector<bool> visited(5, false);
    vector<char> path;

    int curr = idx[start];
    visited[curr] = true;
    path.push_back(start);

    int total = 0;

    for (int step = 1; step < 5; step++) {
        int next = -1;
        int best = INT_MAX;

        for (int i = 0; i < 5; i++) {
            if (!visited[i] && dist[curr][i] < best) {
                best = dist[curr][i];
                next = i;
            }
        }

        visited[next] = true;
        total += best;
        curr = next;
        path.push_back(cities[curr]);
    }

    // return to start
    total += dist[curr][idx[start]];
    path.push_back(start);

    cout << total << "\n";
    for (char c : path)
        cout << c << " ";
}
