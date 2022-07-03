// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1091/

#include <iostream>
#include <map>
using namespace std;

int n, m;
map<int, int> h;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	h[-1] = 200005;
	h[1000000005] = 1;
	for (int i = 0; i < n; i++)
	{
		int hi;
		cin >> hi;
		h[hi]++;
	}
	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		auto ticket = h.lower_bound(ti);
		while (ticket->first > ti)
			ticket--;
		cout << ticket->first << '\n';
		if (--(ticket->second) == 0)
			h.erase(ticket);
	}

	return 0;
}
