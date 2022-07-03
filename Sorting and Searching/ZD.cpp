// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2428

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int64_t n, k, ar[200005], res;
map<int64_t, int64_t> C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int ptr1 = 0, ptr2 = 1;
	C[ar[0]]++;
	while (ptr2 < n)
	{
		if (k == C.size() && C.count(ar[ptr2]) == 0)
		{
			// count all the combinations
			// add the next
			cout << ptr1 << ' ' << ptr2 << '\n';
			res += (ptr2 - ptr1 + 1);
			C[ar[ptr1]]--;
			if (C[ar[ptr1]] == 0)
				C.erase(ar[ptr1]);
			ptr1++;
		}
		else if (k <= C.size())
		{
			// add the next
			C[ar[ptr2++]]++;
		}
		else
		{
			// eliminate the last
			C[ar[ptr1]]--;
			if (C[ar[ptr1]] == 0)
				C.erase(ar[ptr1]);
			ptr1++;
		}
	}

	int dif = ptr2 - ptr1;
	res += (dif + 1) * dif / 2;

	cout << res;

	cout << res;

	return 0;
}