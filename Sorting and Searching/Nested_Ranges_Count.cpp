// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2169

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct range
{
	int64_t start, end, indx;
} ranges[200005];

int64_t n;
set<int> values;
map<int, int> setValues;
int64_t FW[400005], contains[200005], contained[200005];

void update(int64_t indx, int64_t delta)
{
	for (; indx < 400005; indx = indx | (indx + 1))
		FW[indx] += delta;
}

int64_t sum(int64_t r)
{
	int64_t res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += FW[r];
	return res;
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
	for (int64_t i = 0; i < n; i++)
	{
		cin >> ranges[i].start >> ranges[i].end;
		values.insert(ranges[i].start);
		values.insert(ranges[i].end);
		ranges[i].indx = i;
	}

	int64_t ix = 1;
	for (auto it = values.begin(); it != values.end(); ix++, it++)
	{
		setValues[*it] = ix;
	}

	for (int64_t i = 0; i < n; i++)
	{
		ranges[i].start = setValues[ranges[i].start];
		ranges[i].end = setValues[ranges[i].end];
	}

	for (int64_t i = 0; i < n; i++)
	{
		update(ranges[i].end, 1);
	}

	sort(ranges, ranges + n);

	for (int64_t i = 0; i < n; i++)
	{
		update(ranges[i].end, -1);
		contains[ranges[i].indx] = sum(ranges[i].end);
	}

	for (int64_t i = 0; i < n; i++)
	{
		contained[ranges[i].indx] = sum(ranges[i].end);
		update(0, 1);
		update(ranges[i].end + 1, -1);
	}

	for (int64_t i = 0; i < n; i++)
		cout << contains[i] << ' ';
	cout << '\n';

	for (int64_t i = 0; i < n; i++)
		cout << contained[i] << ' ';
	cout << '\n';

	return 0;
}
