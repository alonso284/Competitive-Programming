// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1649

#include <iostream>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

int n, ar[200005], ST[800005], q;

void build(int v, int l, int r)
{
	if (l == r)
		ST[v] = ar[l];
	else
	{
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		ST[v] = min(ST[v * 2], ST[v * 2 + 1]);
	}
}

void update(int v, int l, int r, int pos, int val)
{
	if (l == r)
	{
		ST[v] = val;
		return;
	}

	int m = (l + r) / 2;
	if (pos <= m)
		update(v * 2, l, m, pos, val);
	else
		update(v * 2 + 1, m + 1, r, pos, val);

	ST[v] = min(ST[v * 2], ST[v * 2 + 1]);
}

int rangeMin(int v, int l, int r, int tl, int tr)
{
	if (tl > tr)
		return 1e9 + 5;
	if (l == tl && r == tr)
		return ST[v];

	int m = (l + r) / 2;
	return min(rangeMin(2 * v, l, m, tl, min(tr, m)), rangeMin(2 * v + 1, m + 1, r, max(tl, m + 1), tr));
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
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			int k, u;
			cin >> k >> u;
			k--;
			ar[k] = u;
			update(1, 0, n - 1, k, u);
			break;
		case 2:
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << rangeMin(1, 0, n - 1, a, b) << '\n';
			break;
		}
	}

	return 0;
}
