// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1072

#include <iostream>
using namespace std;

int n;

int64_t ar[10005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ar[1] = 0;
	ar[2] = 6;
	ar[3] = 28;
	ar[4] = 96;
	ar[5] = 252;
	ar[6] = 550;
	ar[7] = 1056;

	cin >> n;
	for (int64_t i = 1; i <= n; i++)
	{
		if (i > 7)
		{
			ar[i] += ar[i - 1];
			ar[i] += (i + i - 2) / 2 * (i + i - 1);

			ar[i] += (i * i - i - i + 1 - 2);
			ar[i] += (i * i - i - i + 1 - 3);
			ar[i] += (i - 4) * (i * i - i - i + 1 - 4);
			ar[i] += (i * i - i - i + 1 - 2);

			ar[i] += (i * i - i - i + 1 - 2);

			ar[i] += (i * i - i - i + 1 - 2);
			ar[i] += (i - 4) * (i * i - i - i + 1 - 4);
			ar[i] += (i * i - i - i + 1 - 3);
			ar[i] += (i * i - i - i + 1 - 2);
		}
		cout << ar[i] << '\n';
	}

	return 0;
}
