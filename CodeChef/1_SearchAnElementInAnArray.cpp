#include <iostream>

int main() {
	int size, toFind;
	std::cin >> size >> toFind;

	bool flag = false;

	for (int i = 0; i < size; i++) {
		int x;
		std::cin >> x;
		if (x == toFind) flag = true;
	}

	if (flag) std::cout << "YES";
	else std::cout << "NO";
}
