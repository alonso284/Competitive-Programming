// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1085

#include <iostream>
using namespace std;

int64_t n, k, ar[200005], MAX, TOTAL;

int64_t check(int64_t top)
{
	int64_t groups = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + ar[i] > top)
		{
			sum = ar[i];
			groups++;
		}
		else
		{
			sum += ar[i];
		}
	}
	groups++;
	return groups;
}

int64_t binary(int64_t ini, int64_t fin)
{
	if (ini == fin)
		return ini;

	int64_t mid = (ini + fin) / 2;
	if (k >= check(mid))
		return binary(ini, mid);
	return binary(mid + 1, fin);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		MAX = max(MAX, ar[i]);
		TOTAL += ar[i];
	}

	cout << binary(MAX, TOTAL);

	return 0;
}