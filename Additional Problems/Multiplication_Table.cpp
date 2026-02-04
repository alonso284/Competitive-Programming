#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int64_t n; cin >> n;
	vector<int64_t> l;
	for(int64_t i = 1; i <= n; i++)
		l.push_back(i*(n-i+1));
	sort(l.begin(), l.end());
	cout << l[n/2] << endl;


	return 0;
}

