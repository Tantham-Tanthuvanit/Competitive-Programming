#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {

    speed

    int n;
    cin >> n;
    int cakes[5] = {0};

    for (int i = 0; i < n; ++i)
        for (int v = 0; v < 5; ++v) {
            int x; cin >> x;
            cakes[v] += x;
        }

    int cakesNeeded = 0;

    cakesNeeded += cakes[0];

    // 3/4
    cakesNeeded += cakes[1];
    int left1o4 = cakes[1];

    int left1o2 = 0;
    // 1/2
    cakesNeeded += cakes[2] / 2;
    if (cakes[2] % 2 == 1) {
        cakesNeeded += 1;
        left1o2 = 1;
    } else {
        left1o2 = 0;
    }

    // 1/4 (calculate the minimum amount needed)
    int use = min(left1o4, cakes[3]);
    cakes[3] -= use;
    left1o4 -= use;

    if (left1o2 == 1) {
        if (cakes[3] >= 2) {
            cakes[3] -= 2;
            left1o2 = 0;
        } else {

        }
    }

    cakesNeeded += cakes[3] / 4;
    cakes[3] = cakes[3] % 4;
    double total18 = cakes[4];

    if (cakes[3] > 0 || left1o2 == 1) {
        cakesNeeded += 1;
        double remainingSpace = 1;
        if (left1o2 == 1) {
            remainingSpace -= 0.5;
        }

        remainingSpace -= cakes[3] * 0.25;

        double leftover_18_capa = remainingSpace / 0.125;
        total18 = (double)cakes[4];
        total18 -= min((double)cakes[4], leftover_18_capa);
    }

    if (total18 > 0) {
        cakesNeeded += ceil(total18 / 8);
    }

    cout << cakesNeeded;

    return 0;

}