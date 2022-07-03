// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1648

#include <iostream>
using namespace std;

int64_t BIT[200005], ar[200005], n, q;

int64_t sum(int r)
{
	int64_t res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += BIT[r];
	return res;
}

int64_t sum(int l, int r)
{
	return sum(r) - (l ? sum(l - 1) : 0);
}

void update(int indx, int delta)
{
	for (; indx < n; indx = indx | (indx + 1))
		BIT[indx] += delta;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		update(i, ar[i]);
	}

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
			update(k, u - ar[k]);
			ar[k] = u;
			break;
		case 2:
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << sum(a, b) << '\n';
			break;
		}
	}

	return 0;
}
