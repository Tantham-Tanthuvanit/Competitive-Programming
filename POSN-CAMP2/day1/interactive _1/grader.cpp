#include "search.h"
vector<int> A;
int t = 0, n = 0, key = 0;

int seek(int i)
{
	if ( A[i] > key )
	{
		return 1;
	}
	else if( A[i] < key )
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        A.push_back(t);
    }

	sort(A.begin(), A.end());
    cin >> key;
    cout << search(n) << endl;
    return 0;
}
