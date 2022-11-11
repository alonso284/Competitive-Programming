// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1083

#include <iostream>
using namespace std;

int64_t n, sum, in;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> in;
		sum += in;
	}

	cout << n * (n + 1) / 2 - sum;

	return 0;
}