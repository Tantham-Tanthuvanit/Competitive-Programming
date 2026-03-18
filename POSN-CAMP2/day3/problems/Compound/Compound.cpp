#include<bits/stdc++.h>
#define ULTRA ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int findClose(const string &s, int i){
    int cnt = 0;
    for(int j = i; j < s.size(); j++){
        if(s[j] == '(') cnt++;
        else if(s[j] == ')') cnt--;
        if(cnt == 0) return j;
    }
    return -1;
}

void split(const string &s, int &val, string &L, string &R){
    val = s[0] - '0';

    if(s.size() == 1){
        L = R = "";
        return;
    }

    int l1 = 1;
    int r1 = findClose(s, l1);
    L = s.substr(l1+1, r1-l1-1);

    int l2 = r1+1;
    int r2 = findClose(s, l2);
    R = s.substr(l2+1, r2-l2-1);
}

string solve(string a, string b){
    if(a.empty() || b.empty()) return "";

    int va, vb;
    string aL,aR,bL,bR;

    split(a, va, aL, aR);
    split(b, vb, bL, bR);

    int sum = va + vb;

    string L = "";
    string R = "";

    if(!aL.empty() && !bL.empty())
        L = solve(aL, bL);

    if(!aR.empty() && !bR.empty())
        R = solve(aR, bR);

    return to_string(sum) + "(" + L + ")(" + R + ")";
}

int main(){
    ULTRA

    string s1, s2;
    cin >> s1 >> s2;

    cout << solve(s1, s2);
}
