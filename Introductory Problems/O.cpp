// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1622

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <chrono>
#include <set>
using namespace std;

string s, out;
int64_t fact[9], abc[26], res = 1, T;
set<int> used;
set<string> usedS;

void calcFact()
{
	fact[0] = 1;
	for (int64_t i = 1; i <= 8; i++)
		fact[i] = fact[i - 1] * i;
}

int64_t C(int64_t n, int64_t k)
{
	return fact[n] / (fact[k] * fact[n - k]);
}

void newString(int inx)
{
	if (inx == s.size())
	{
		if (usedS.count(out))
			return;
		cout << out << '\n';
		usedS.insert(out);
		return;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (!used.count(i))
		{
			used.insert(i);
			out.push_back(s[i]);
			newString(inx + 1);
			used.erase(i);
			out.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	calcFact();
	cin >> s;
	sort(s.begin(), s.end());

	for (auto it : s)
		abc[it - 'a']++;

	int64_t left = s.size();
	for (auto it : abc)
	{
		res *= C(left, it);
		left -= it;
	}

	cout << res << endl;
	newString(0);

	return 0;
}
