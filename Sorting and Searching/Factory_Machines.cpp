// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1620

#include <iostream>
#include <map>
using namespace std;
#define INFY 9223372036854775806

int64_t n, t, k[200005];

int64_t evaluate(int64_t T)
{
	int64_t res = 0;
	for (int64_t i = 0; i < n; i++)
	{
		res += T / k[i];
		if (res >= t)
			return t;
	}
	return res;
}

int64_t binary(int64_t ini, int64_t fin)
{
	if (ini >= fin)
		return ini;

	int64_t mit = (ini + fin) / 2;
	if (evaluate(mit) >= t)
		return binary(ini, mit);
	return binary(mit + 1, fin);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> t;
	for (int64_t i = 0; i < n; i++)
		cin >> k[i];

	cout << binary(1, INFY);
	return 0;
}
