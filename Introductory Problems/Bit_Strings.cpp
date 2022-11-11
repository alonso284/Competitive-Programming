// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1617/

#include <iostream>
using namespace std;
#define MOD 1000000007

int64_t n, res = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		res += res;
		res %= MOD;
	}

	cout << res;

	return 0;
}
