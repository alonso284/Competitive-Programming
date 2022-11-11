// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1646

#include <iostream>
using namespace std;

int64_t n, q, ar[200005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	for (int i = 1; i <= n; i++)
		ar[i] += ar[i - 1];

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << ar[b] - ar[a - 1] << '\n';
	}

	return 0;
}
