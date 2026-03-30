#include <bits/stdc++.h>
using namespace std;

int mod(int n, int exp, int md) {
    // base case
    if (exp == 0) {
        return 1;
    }

    if (exp % 2 == 1) {
        return (n * (mod(n, exp-1, md)))%md;
    } else {
        return (mod(n,exp/2,md) * mod(n,exp/2,md))%md;
    }
}

int main() {
    cout << mod(3, 600, 5) << endl;
}