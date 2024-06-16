#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_function(string s){
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i < r){
			z[i] = min(r - i, z[i - l]);
		}
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
			z[i]++;
		}
		if(i + z[i] > r){
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

vector<int> prefix_function(string s){
	int n = (int)s.length();
	vector<int> pi(n);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
	string s;
	cin >> s;
	vector<int> zf = z_function(s);
	vector<int> pi = prefix_function(s);

	for(int i = 0; i < s.size(); i++)
		cout << zf[i] << ' ';
	cout << endl;
	for(int i = 0; i < s.size(); i++)
		cout << pi[i] << ' ';

	return 0;
}
