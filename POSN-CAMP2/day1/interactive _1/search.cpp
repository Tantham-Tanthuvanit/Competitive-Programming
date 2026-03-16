#include "search.h"
int search(int N)
{
	int left = 0;
	int right = N-1;

	int ans = 0;

	while (true) {
		int skRes = seek((left + right)/2);

		ans++;

		if (skRes == -1) left = ((left+right)/2)+1;
		else if (skRes == 1) right = ((left+right)/2)-1;
		else return ans;
	}
}
