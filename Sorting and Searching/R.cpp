// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2168

#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
using namespace std;
#define INF 1e9 + 7

struct range
{
	int start, end, indx;
} ranges[200005];

int n;
bool contains[200005], contained[200005];
stack<range> rangeStack;
vector<int> FW(200005, INF);

int getmin(int r)
{
	int res = INF;
	for (; r >= 0; r = (r & (r + 1)) - 1)
	{
		res = min(res, FW[r]);
	}
	return res;
}

void update(int idx, int val)
{
	for (; idx <= n; idx = idx | (idx + 1))
	{
		FW[idx] = min(FW[idx], val);
	}
}

bool operator<(range a, range b)
{
	if (a.start != b.start)
		return a.start < b.start;
	else
		return a.end > b.end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ranges[i].start >> ranges[i].end;
		ranges[i].indx = i;
	}

	sort(ranges, ranges + n);
	for (int i = 0; i < n; i++)
	{
		while (!rangeStack.empty() && rangeStack.top().end < ranges[i].start)
		{
			rangeStack.pop();
		}
		while (!rangeStack.empty() && rangeStack.top().end < ranges[i].end)
		{
			rangeStack.pop();
		}

		if (rangeStack.empty())
			rangeStack.push(ranges[i]);
		else
			contained[ranges[i].indx] = true;
	}

	for (int i = n - 1; i >= 0; i--)
		update(n - i - 1, ranges[i].end);

	for (int i = 0; i < n - 1; i++)
		if (getmin(n - i - 2) <= ranges[i].end)
			contains[ranges[i].indx] = true;

	for (int i = 0; i < n; i++)
		cout << contains[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << contained[i] << ' ';

	return 0;
}