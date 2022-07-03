// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1662

#include <iostream>
#include <map>
using namespace std;

int64_t n, ar[200005], res;
map<int64_t, int> prefixes;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	prefixes[0]++;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		(((ar[i] += ar[i - 1]) %= n) += n) %= n;
		res += prefixes[ar[i]];
		prefixes[ar[i]]++;
	}

	cout << res;

	return 0;
}