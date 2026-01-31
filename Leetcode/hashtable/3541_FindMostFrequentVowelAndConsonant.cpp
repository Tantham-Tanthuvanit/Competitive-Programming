#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	int maxFreqSum(string s) {

		int vowel = 0;
		int consonant = 0;
		
		unordered_map<char,int> mp;

		for (char c : s) {
			mp[c]++;
		}

		for (char ch = 'a'; ch <= 'z'; ch++) {
			if (is_vowel(ch)) {
				vowel = max(vowel, mp[ch]);
			} else {
				consonant = max(consonant, mp[ch]);
			}
		}
		
		return vowel + consonant;

	}
};

int main() {
	return 0;
}
