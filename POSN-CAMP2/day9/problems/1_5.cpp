#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define int long long

int dp[101]={0};
int fib(int n) {
	if (n==1||n==2||n==3) return 1;
	if(n==4)return 2;
	if(!dp[n-1]) dp[n-1] = fib(n-1);
	if(!dp[n-4]) dp[n-4] = fib(n-4);
	dp[n]= dp[n-1] + dp[n-4];
	return dp[n];	
}
signed main(){
   int a;
   cin >> a;
   cout << fib(a);
}
