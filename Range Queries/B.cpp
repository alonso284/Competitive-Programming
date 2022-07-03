// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1647

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INFY 1000000000

int RMQ[200005][21];
int ar[200005], n, q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> RMQ[i][0];

	for (int j = 1; j <= 20; j++)
		for (int i = 0; i + (1 << (j - 1)) < n; i++)
			RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);

	while (q--)
	{
		int a, b, dif;
		cin >> a >> b;
		a--;
		b--;
		dif = b - a + 1;
		cout << min(RMQ[a][int(log2(dif))], RMQ[a + (dif - (1 << int(log2(dif))))][int(log2(dif))]) << '\n';
	}

	return 0;
}
