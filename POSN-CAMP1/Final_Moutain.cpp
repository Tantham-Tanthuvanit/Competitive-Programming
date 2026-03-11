#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	uint16_t count;
	cin >> count;

	vector<uint16_t> moutains(count, 0);

	uint16_t height, width;

	for (int i = 0; i < count; i++) {
		cin >> moutains[i];
		height = max(height, moutains[i]);
		width += moutains[i];
	}

	if (count == 1 && moutains[0] == 0) {
		cout << "ERROR";
		return 0;
	}

	width *= 2;

	vector<vector<char>> map(height, vector<char>(width, ' '));

	int cnt = 0;

	for (auto& mnt : moutains) {
		for (int i = 0; i < mnt; i++) {
			map[i][cnt] = '/';
			cnt++;
		}

		for (int i = mnt-1; i >= 0; i--) {
			map[i][cnt] = '\\';
			cnt++;
		}
	}

	for (int i = height-1; i >= 0; i--) {
		for (auto& c : map[i]) {
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}
