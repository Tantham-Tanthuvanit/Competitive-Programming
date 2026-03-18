#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	map<int, string> times;

	while (true) {
		string name;
		string a, b, c;
		cin >> name >> a >> b >> c;

		if (name == "-") break;

		times[stoi(a+b+c)] = name;
	}

	for (const auto& i : times) { 
		cout << i.second << ' ';
	}


	return 0;
	
}
