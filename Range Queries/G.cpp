// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1652

#include <iostream>
using namespace std;

int n, q, forest[1005][1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char tile;
			cin >> tile;
			forest[i][j] = (tile == '*') + forest[i - 1][j] + forest[i][j - 1] - forest[i - 1][j - 1];
		}

	while (q--)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << forest[y2][x2] - forest[y2][x1 - 1] - forest[y1 - 1][x2] + forest[y1 - 1][x1 - 1] << '\n';
	}

	return 0;
}
