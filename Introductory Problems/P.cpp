// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1623

#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int64_t n, ar[25], MIN = (1 << 30);

void alter(int64_t indx, int64_t A, int64_t B)
{
	if (indx == n)
	{
		if (A > B)
		{
			if (A - B < MIN)
				MIN = A - B;
		}
		else
		{
			if (B - A < MIN)
				MIN = B - A;
		}
		return;
	}

	alter(indx + 1, A + ar[indx], B);
	alter(indx + 1, A, B + ar[indx]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	alter(0, 0, 0);
	cout << MIN;

	return 0;
}
