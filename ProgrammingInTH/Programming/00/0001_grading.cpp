#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main() {

    int grade = 0;
    for (int i = 0; i < 3; ++i) {
        int x; cin >> x;
        grade += x;
    }

    if (grade >= 80) cout << "A";
    else if (grade >= 75) cout << "B+";
    else if (grade >= 70) cout << "B";
    else if (grade >= 65) cout << "C+";
    else if (grade >= 60) cout << "C";
    else if (grade >= 55) cout << "D+";
    else if (grade >= 50) cout << "D";
    else cout << "F";

    return 0;
}