// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1644
 
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, A, B; cin >>N >> A >> B;
	long long ar[N+1], prfx[N+1+100] ;
	set<pair<long long,long long> > prefixes;
	prfx[0] = ar[0] = 0;

	for(long long i = 1; i <= N; i++) {
		cin >> ar[i];
		prfx[i] = ar[i] + prfx[i-1];
		// cout << prfx[i] << ' ';
	}

	// cout << endl;

	for(long long i = A; i < B; i++){
		// cout << "insertando " << prfx[i] << endl;
		prefixes.insert(make_pair(prfx[i], i));
	}


	long long biggest = prfx[B];
	for(long long i = B; i <= N; i++){

		// cout << "insertando " << prfx[i] << endl;
		prefixes.insert(make_pair(prfx[i], i));

		// cout << "restando " << prfx[i-B] << endl;
		auto pp = prefixes.end(); pp--;
		biggest = max(biggest, (long long)(pp->first - prfx[i-B]));

		// cout << "quitando " << prfx[i-(B-A)] << endl;
		prefixes.erase(make_pair(prfx[i-(B-A)], i-(B-A)));


	}

	for(int i = N+1; i < N+B-A+1; i++){

		// cout << "restando " << prfx[i-B] << endl;

		auto pp = prefixes.end(); pp--;
		biggest = max(biggest, (long long)(pp->first - prfx[i-B]));

		// cout << "quitando " << prfx[i-(B-A)] << endl;
		prefixes.erase(make_pair(prfx[i-(B-A)], i-(B-A)));
	}

	cout << biggest;


 

	return 0;
}

