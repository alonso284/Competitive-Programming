// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1632
 
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
long long movies;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	set< pair<long long,long long> > lastAvailable;
	long long n, k;
	cin >> n >> k;
	pair<long long,long long> schedules[n];

	for(long long i = 0; i < n; i++){
		long long b, e; cin >> b >> e; schedules[i] = make_pair(e, b);
	} sort(schedules, schedules+n);

	for(long long i = 0; i < k; i++)
		lastAvailable.insert(make_pair(0, i));

	for(long long i = 0; i < n; i++){


		auto pp = lastAvailable.upper_bound(make_pair(schedules[i].second, 0));
		if(pp != lastAvailable.begin()) pp--;
		auto person = *pp;
		if(schedules[i].second >= person.first){
			lastAvailable.erase(pp);
			person.first = schedules[i].first;
			lastAvailable.insert(person);
			movies++;
		}
	}

	cout << movies;
 

	return 0;
}

