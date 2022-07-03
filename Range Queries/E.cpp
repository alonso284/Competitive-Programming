// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1650

#include <iostream>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

int n, q, ar[200005], ST[800005];

void build(int v, int l, int r)
{
	if (l == r)
		ST[v] = ar[l];
	else
	{
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		ST[v] = ST[2 * v] ^ ST[2 * v + 1];
	}
}

int rangeXOR(int v, int l, int r, int tl, int tr)
{
	if (tl > tr)
		return 0;
	if (tl == l && tr == r)
		return ST[v];

	int m = (l + r) / 2;
	return (rangeXOR(v * 2, l, m, tl, min(m, tr)) ^ rangeXOR(2 * v + 1, m + 1, r, max(tl, m + 1), tr));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	forn(i, n) cin >> ar[i];

	build(1, 0, n - 1);

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << rangeXOR(1, 0, n - 1, a, b) << '\n';
	}

	return 0;
}
