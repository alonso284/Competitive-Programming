// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1071

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int64_t n, x, y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--)
	{
		cin >> y >> x;
		if (x >= y)
		{
			if (x % 2)
			{
				cout << x * x - y + 1;
			}
			else
			{
				cout << x * x - x - x + y + 1;
			}
		}
		else
		{
			if (y % 2)
			{
				cout << y * y - y - y + x + 1;
			}
			else
			{
				cout << y * y - x + 1;
			}
		}
		cout << '\n';
	}

	return 0;
}
