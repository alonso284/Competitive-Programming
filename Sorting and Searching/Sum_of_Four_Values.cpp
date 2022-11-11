// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1642

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int64_t n, k, a[1005];
map<int, vector<pair<int, int>>> dell;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			dell[a[i] + a[j]].push_back({i + 1, j + 1});
		}
	}

	if (dell.empty())
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	auto ptr1 = dell.begin(), ptr2 = dell.end();
	ptr2--;

	while (ptr1->first <= ptr2->first)
	{
		if (ptr1->first + ptr2->first == k)
		{
			for (auto &p1 : ptr1->second)
				for (auto &p2 : ptr2->second)
					if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second)
					{
						cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second;
						return 0;
					}
			if (ptr1->first == ptr2->first)
				break;
			ptr1++;
		}
		if (ptr1->first == ptr2->first)
			break;
		if (ptr1->first + ptr2->first < k)
			ptr1++;
		if (ptr1->first + ptr2->first > k)
			ptr2--;
	}

	cout << "IMPOSSIBLE";

	return 0;
}
