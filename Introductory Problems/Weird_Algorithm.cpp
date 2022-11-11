// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/result/1068/

#include <iostream>
using namespace std;

int64_t n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << n << ' ';
	while (n != 1)
	{
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}