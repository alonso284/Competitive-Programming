// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1634

#include <iostream>
#include <algorithm>
using namespace std;
#define INFY 1000000000000000000

int64_t DP[1000005];
int64_t n, x, c[105];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 1; i <= x; i++)
		DP[i] = INFY;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + c[i] <= x; j++)
		{
			DP[j + c[i]] = min(DP[j + c[i]], DP[j] + 1);
		}
	}

	cout << (DP[x] == INFY ? -1 : DP[x]);

	return 0;
}
