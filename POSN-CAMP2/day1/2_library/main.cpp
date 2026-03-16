#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	vector<int> scores;
	unordered_map<int, string> mp;

	while (true) {
		string name, grade, score;

		cin >> name >> grade >> score;

		if (name == "-" && grade == "-" && score == "-") break;

		scores.push_back(stoi(score));

		mp[stoi(score)] = name + " " + grade;
	}

	sort(scores.begin(), scores.end(), greater<int>());

	for (int s : scores) {
		cout << mp[s] << ' ' << s << endl;
	}

	return 0;

}
