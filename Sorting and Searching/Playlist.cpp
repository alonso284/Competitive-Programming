// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1141

#include <iostream>
#include <map>
using namespace std;

int n, ar[200005], l = 1, r = 1, MAX;
map<int, int> range;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	while (r <= n)
	{
		int Rsize = (r - l + 1);
		range[ar[r]]++;
		while (range.size() != Rsize)
		{
			range[ar[l]]--;
			if (range[ar[l]] == 0)
				range.erase(ar[l]);
			l++;
			Rsize--;
		}
		if (Rsize > MAX)
			MAX = Rsize;
		r++;
	}

	cout << MAX;

	return 0;
}
