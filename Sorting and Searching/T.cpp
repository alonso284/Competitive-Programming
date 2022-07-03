// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1164

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct range
{
	int start, end, indx, room;
} ranges[200005];

bool operator<(range a, range b)
{
	return a.end > b.end;
}

bool byStart(range a, range b)
{
	return a.start < b.start;
}

bool byIndx(range a, range b)
{
	return a.indx < b.indx;
}

priority_queue<range> Q;
int n, R;

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

	sort(ranges, ranges + n, byStart);

	for (int i = 0; i < n; i++)
	{
		if (Q.empty() || Q.top().end >= ranges[i].start)
		{
			ranges[i].room = Q.size() + 1;
			R = max(R, ranges[i].room);
			Q.push(ranges[i]);
		}
		else
		{
			ranges[i].room = Q.top().room;
			Q.pop();
			Q.push(ranges[i]);
		}
	}
	sort(ranges, ranges + n, byIndx);

	cout << R << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << ranges[i].room << ' ';
	}

	return 0;
}