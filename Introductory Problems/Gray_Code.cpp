// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/result/2205/

#include <iostream>
#include <unordered_set>
using namespace std;

int n, bitLim;
unordered_set<int> vis;

void printBin(int m)
{
	for (int i = 0; i < bitLim; i++)
		cout << bool(m & (1 << i));
	cout << '\n';
}

void next(int m)
{
	vis.insert(m);
	printBin(m);
	for (int i = 0; i < bitLim; i++)
		if (!vis.count(m ^ (1 << i)))
			next(m ^ (1 << i));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> bitLim;
	next(0);

	return 0;
}
