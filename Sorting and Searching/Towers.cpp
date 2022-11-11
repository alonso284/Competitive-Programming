// Alonso Huerta Escalante
// Link:

#include <iostream>
#include <map>
using namespace std;
#define infy 1000000005

int n, temp, xTowers;
map<int, int> towers;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	towers[infy]++;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		map<int, int>::iterator it = towers.upper_bound(temp);
		if (it->first != infy)
		{
			it->second--;
			if (it->second == 0)
				towers.erase(it);
		}
		towers[temp]++;
	}

	for (auto &it : towers)
		xTowers += it.second;

	cout << xTowers - 1;

	return 0;
}
