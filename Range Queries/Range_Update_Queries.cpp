// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1651

#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int64_t n, q, ST[800005];

void build(int v, int l, int r)
{
	if (l == r)
		cin >> ST[v];
	else
	{
		int m = (l + r) / 2;
		build(v << 1, l, m);
		build(v << 1 | 1, m + 1, r);
	}
}

void update(int v, int l, int r, int tl, int tr, int val)
{
	if (tl > tr)
		return;

	if (tl == l && tr == r)
	{
		ST[v] += val;
	}
	else
	{
		int m = (l + r) / 2;
		ST[v << 1] += ST[v];
		ST[v << 1 | 1] += ST[v];
		ST[v] = 0;
		update(v << 1, l, m, tl, min(tr, m), val);
		update(v << 1 | 1, m + 1, r, max(m + 1, tl), tr, val);
	}
}

int64_t query(int v, int l, int r, int pos)
{
	if (l == r)
		return ST[v];
	else
	{
		int m = (l + r) / 2;
		ST[v << 1] += ST[v];
		ST[v << 1 | 1] += ST[v];
		ST[v] = 0;
		if (pos <= m)
			return query(v << 1, l, m, pos);
		else
			return query(v << 1 | 1, m + 1, r, pos);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	build(1, 1, n);
	while (q--)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int a, b, u;
			cin >> a >> b >> u;
			update(1, 1, n, a, b, u);
		}
		else
		{
			int x;
			cin >> x;
			cout << query(1, 1, n, x) << '\n';
		}
	}

	return 0;
}
