// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1076/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, x, BIT[400005], ar[200005], og[200005];
map<int, int> realVal, changeValue;

void add(int indx, int delta)
{
	for (; indx <= n * 2; indx += indx & (-indx))
		BIT[indx] += delta;
}

int mean()
{
	int i = 0;
	int bit = 1 << 20;
	int sum = 0;
	for (; bit; bit >>= 1)
	{
		if (i + bit > n * 2)
			continue;
		if (BIT[i + bit] + sum < ((x + 1) >> 1))
		{
			i += bit;
			sum += BIT[i];
		}
	}
	return i + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		og[i] = ar[i];
	}

	sort(og, og + n);
	int temp = 1;
	changeValue[temp] = og[0];
	realVal[og[0]] = temp;

	for (int i = 1; i < n; i++)
	{
		if (og[i] != og[i - 1])
			temp++;
		changeValue[temp] = og[i];
		realVal[og[i]] = temp;
	}

	for (int i = 0; i < n; ++i)
	{
		ar[i] = realVal[ar[i]];
	}

	for (int i = 0; i < x; i++)
	{
		add(ar[i], 1);
	}
	cout << changeValue[mean()] << ' ';

	for (int i = x; i < n; i++)
	{
		add(ar[i], 1);
		add(ar[i - x], -1);
		cout << changeValue[mean()] << ' ';
	}

	return 0;
}