// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1070

#include <iostream>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if (n == 2 || n == 3)
	{
		cout << "NO SOLUTION";
		return 0;
	}
	if (n == 5)
	{
		cout << "4 2 5 3 1";
		return 0;
	}
	if (n == 4)
	{
		cout << "3 1 4 2";
		return 0;
	}

	if (n % 2)
	{
		cout << n << ' ';
		n--;
	}

	for (int i = 1; i <= n / 2; i++)
	{
		cout << i << ' ' << n / 2 + i << ' ';
	}

	return 0;
}
