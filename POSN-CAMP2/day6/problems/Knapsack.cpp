#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

struct item {
	int weight;
	int value;
};

vector<item> items;
int cnt = 0;

int calculateMaxSack(int remainingCapa, int numberOfItemsLeft, const vector<item>& items) {
	// Base case, if no items left or sack is full then return
	if (numberOfItemsLeft == 0 || remainingCapa == 0) return 0;

	cnt++;

	int currentItemIndex = numberOfItemsLeft - 1;
	int currentItemWeight = items[currentItemIndex].weight;
	int currentItemValue = items[currentItemIndex].value;

	// if weight of current item is over remaiting capa dont iclude it
	if (currentItemWeight > remainingCapa)
		return calculateMaxSack(remainingCapa, numberOfItemsLeft - 1, items);

	// calculate max by trying bth options
	else {
		int valueIfIncluded = currentItemValue + calculateMaxSack(remainingCapa - currentItemWeight, numberOfItemsLeft - 1, items);
		int valueIfExcluded = calculateMaxSack(remainingCapa, numberOfItemsLeft - 1, items);

		return max(valueIfIncluded, valueIfExcluded);
	}
}

int main() {

	vector<item> items = {{10,10},{14,12},{7,6},{12,10},{6,2},{24,6}};

	int weightCapa = 23;
	int totalNumOfItems = items.size();

	int maxVal = calculateMaxSack(weightCapa, totalNumOfItems, items);
	cout << maxVal << endl;
	cout << cnt;

	return 0;

}
