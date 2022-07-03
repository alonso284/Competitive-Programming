// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1640

#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

pii ar[200005];
int n, x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i].first;
		ar[i].second = i + 1;
	}
	sort(ar, ar + n);

	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		if (ar[i].first + ar[j].first == x)
		{
			cout << ar[i].second << ' ' << ar[j].second;
			return 0;
		}
		if (ar[i].first + ar[j].first > x)
			j--;
		else
			i++;
	}

	cout << "IMPOSSIBLE";

	return 0;
}
