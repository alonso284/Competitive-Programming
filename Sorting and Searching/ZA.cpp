// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1660

#include <iostream>
using namespace std;

int64_t n, k, a[200005], sum, poss;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ptr1 = 0, ptr2 = 0;
	while (true)
	{
		if (sum < k)
		{
			if (ptr2 == n)
				break;
			sum += a[ptr2++];
		}
		else if (sum > k)
		{
			sum -= a[ptr1++];
		}
		if (sum == k)
		{
			poss++;
			sum -= a[ptr1++];
		}
	}

	cout << poss;

	return 0;
}