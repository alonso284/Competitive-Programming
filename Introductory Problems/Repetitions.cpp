// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1069

#include <iostream>
#include <string>
using namespace std;

int n, t = 1, c = 1;
string adn;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> adn;
	for (int i = 0; i < adn.size() - 1; i++)
	{
		if (adn[i] == adn[i + 1])
			c++;
		else
			c = 1;
		if (c > t)
			t = c;
	}

	cout << t;

	return 0;
}
