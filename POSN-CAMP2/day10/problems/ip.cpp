#include <bits/stdc++.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define int long long
#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL);

bool ipv4(string s) {
	stringstream ss(s);
	vector<string> parts;

	if (s.empty()) return false;

	string part;
	while (getline(ss, part, '.'))
		parts.push_back(part);

	if (parts.size() != 4) return false;

	for (string s : parts) {
		if (s.empty()) return false;
		for (char c : s) { if (c < '0' || c > '9') return false; }
		int num = stoi(s);
		if (num < 0 || num > 255) return false;
	}

	return true;
}

bool ipv6(string s) {
	stringstream ss(s);
	vector<string> parts;
	string part;

	if (s.empty()) return false;

	while (getline(ss,part,':'))
		parts.push_back(part);

	if (parts.size() != 8) return false;
	
	for (string s : parts) {
		if (s.empty() || s.size() > 4) return false;
		for (char c : s ) { if (!isxdigit((unsigned char)c)) return false; }
	}
	return true;
}

signed main() {
	string ip; cin >> ip;
	if		(ipv4(ip)) cout << "IPv4";
	else if (ipv6(ip)) cout << "IPv6";
	else cout << "Neither";
}
