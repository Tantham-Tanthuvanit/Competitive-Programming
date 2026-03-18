#include<bits/stdc++.h>
#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main(){
    ULTRA
    string S;
    cin >> S;

    stack<int> st;

    for(char c : S){
        if(isdigit(c)){
            st.push(c - '0');
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res;

            if(c == '+') res = a + b;
            else if(c == '-') res = a - b;
            else if(c == '*') res = a * b;
            else if(c == '/') res = a / b;
            else if(c == '^') res = pow(a, b);

            st.push(res);
        }
    }

    cout << st.top();

    return 0;
}
