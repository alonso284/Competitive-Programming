// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2431

#include <iostream>
#include <cmath>
using namespace std;

int64_t q, k, limits[19], tensPOW[19];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int64_t c = 0;
	int64_t tens = 1;
	tensPOW[0] = 1;
	for (int64_t i = 1; i < 18; i++)
	{
		c += 9 * tens * i;
		limits[i] = c;
		tens *= 10;
		tensPOW[i] = tens;
	}

	cin >> q;
	while (q--)
	{
		cin >> k;
		int64_t len, at, lookFor, pos;
		for (int64_t i = 0; i < 18; i++)
		{
			if (limits[i] <= k && k <= limits[i + 1])
			{
				len = i + 1;
				break;
			}
		}
		k -= limits[len - 1];
		at = (k + len - 1) / len;
		lookFor = tensPOW[len - 1] + at - 1;
		pos = len - k % len;
		if (pos == len)
			pos = 0;
		cout << int64_t(lookFor / tensPOW[pos]) % 10 << '\n';
	}

	return 0;
}
