// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1092

#include <iostream>
#include <vector>
using namespace std;

int64_t n, sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	sum = n * (n + 1) / 2;
	if (sum % 2)
		cout << "NO";
	else
	{
		vector<int> a, b;
		cout << "YES\n";
		if (n % 2)
		{
			a.push_back(n);
			n--;
		}

		for (int i = 1; i <= n / 2 / 2; i++)
		{
			a.push_back(i);
			a.push_back(n - i + 1);
		}
		for (int i = n / 2 / 2 + 1; i <= n / 2; i++)
		{
			b.push_back(i);
			b.push_back(n - i + 1);
		}

		cout << a.size() << '\n';
		for (auto &it : a)
			cout << it << ' ';
		cout << '\n';
		cout << b.size() << '\n';
		for (auto &it : b)
			cout << it << ' ';
	}

	return 0;
}
