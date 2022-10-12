// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1749

#include <iostream>
using namespace std;

int BIT[200005], ar[200005], n, b;

void del(int indx)
{
	for (; indx <= n; indx += indx & -indx)
		BIT[indx]--;
}

int lookFor(int x)
{
	int sum = 0, indx = 0;
	for (int i = 1 << b; i; i >>= 1)
		if (indx + i > n)
			continue;
		else if (sum + BIT[indx + i] < x)
		{
			sum += BIT[indx + i];
			indx += i;
		}
	del(indx + 1);
	return indx + 1;
}

void findBit()
{
	int temp = n;
	while (temp >>= 1)
		b++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	findBit();
	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	for (int i = 1; i <= n; i <<= 1)
		for (int j = i; j <= n; j += (i << 1))
			BIT[j] = i;

	int c = n;
	while (c--)
	{
		int g;
		cin >> g;
		cout << ar[lookFor(g)] << ' ';
	}

	return 0;
}
