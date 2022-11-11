// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1633

#include <iostream>
using namespace std;
#define MOD 1000000007

int DP[1000005], n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[1] = DP[2] = DP[3] = DP[4] = DP[5] = DP[6] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
		for (int j = (i > 6 ? i - 6 : 1); j < i; j++)
		{
			DP[i] += DP[j];
			DP[i] %= MOD;
		}

	cout << DP[n];

	return 0;
}
