// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1143

#include <iostream>
using namespace std;

// es un bit donde haces un meta binary y quitas al primero mayor
int n, m, s[800020];

void build(int v, int l, int r)
{
	if (l == r)
	{
		cin >> s[v];
	}
	else
	{
		int m = (l + r) / 2;
		build(v << 1, l, m);
		build(v << 1 | 1, m + 1, r);
		s[v] = max(s[v << 1], s[v << 1 | 1]);
	}
}

int query(int v, int l, int r, int val)
{
	if (l == r)
	{
		s[v] -= val;
		return l;
	}
	else
	{
		int m = (l + r) / 2;

		int res;
		if (s[v << 1] >= val)
			res = query(v << 1, l, m, val);
		else
			res = query(v << 1 | 1, m + 1, r, val);

		s[v] = max(s[v << 1], s[v << 1 | 1]);
		return res;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	build(1, 1, n);

	while (m--)
	{
		int g;
		cin >> g;
		if (g <= s[1])
			cout << query(1, 1, n, g) << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}
