// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1077/
 
#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;
 
long long sumaMenores, sumaMayores;
long long n, k;
set< pair<long long,long long> > menores, mayores;
 
void level(){

	if(mayores.size() > menores.size()){
		set< pair<long long,long long> >::iterator it = mayores.begin();
		sumaMayores -= (*it).first;
		sumaMenores += (*it).first;
		menores.insert(*it);
		mayores.erase(it);	
	}else{
		set< pair<long long,long long> >::iterator it = menores.end(); it--;
		sumaMayores += (*it).first;
		sumaMenores -= (*it).first;
		mayores.insert(*it);
		menores.erase(it);	
	}
	
}
 
long long res(){
	return abs(sumaMayores - sumaMenores - (k%2? mayores.begin() -> first:0 ));
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n >> k;
	long long a[n];
	for(long long i = 0; i < k; i++){
		cin >> a[i];
		sumaMayores += a[i];
		mayores.insert(make_pair(a[i], i));
	}
 
	while(mayores.size()-menores.size() > 1) level();
	cout << res() << ' ';
 
	for(long long i = k; i < n; i++){
		if(mayores.erase(make_pair(a[i-k], i-k))) sumaMayores -= a[i-k];
		if(menores.erase(make_pair(a[i-k], i-k))) sumaMenores -= a[i-k];
 

		cin >> a[i];
 		if(mayores.begin() -> first <= a[i]){
 			sumaMayores += a[i];
			mayores.insert(make_pair(a[i], i));
 		}else{
 			sumaMenores += a[i];
			menores.insert(make_pair(a[i], i));
 		}
 
		if(!(mayores.size()-menores.size()==0 || mayores.size()-menores.size()==1)) level();
 
		cout << res() << ' ';
	}
	return 0;
}

