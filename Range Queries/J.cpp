// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/

#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, q;
int ar[200005], BIT[1000000];
vector< pair<char, pair<long long, long long> > > queries;
// set <int> usedValues;
unordered_map<int, long long> newValues;
vector<long> usedValues;

void insert(int idx);
void del(int idx);
int querie(int r);

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> ar[i];
		usedValues.push_back(ar[i]);
	}

	int questions = 0;
	while(q--){
		char command; int a, b;
		cin >> command >> a >> b;
		queries.push_back(make_pair(command, make_pair(a, b)));
		
		switch(command){
			case '?':
				usedValues.push_back(a-1);
				usedValues.push_back(a);
				questions++;
			case '!':
				usedValues.push_back(b);
		}
	}

	if(!questions) return 0;

	usedValues.push_back(-1);
	sort(usedValues.begin(), usedValues.end());

	int p = 1;
	for(int i = 1; i < (int)usedValues.size(); i++){
		if(usedValues[i] != usedValues[i-1]) newValues[usedValues[i]] = p++;
	}

//	cout << endl;
//	for(auto& it:newValues) cout << it.first << ' ' << it.second << endl;

	for(int i = 1; i <= n; i++){
		insert(newValues[ar[i]]);
	}

	for(auto& q:queries){
		switch(q.first){
			case '?':
				cout << querie(newValues[q.second.second]) - querie(newValues[q.second.first-1]) << ' ';
				break;
			case '!':
				del(newValues[ar[q.second.first]]);
				ar[q.second.first] = q.second.second;
				insert(newValues[ar[q.second.first]]);
		}
	}

	
		
	return 0;
}

void insert(int idx){
	for (; idx <= (int)newValues.size(); idx = idx | (idx + 1))
            BIT[idx] ++;
}

int querie(int r){
	if(r == 0) return 0;
	int ret = 0;
       for (; r >= 0; r = (r & (r + 1)) - 1)
           ret += BIT[r];
//	 cout << ret << endl;
    return ret;
}

void del(int idx){
    for (; idx <= (int)newValues.size(); idx = idx | (idx + 1))
 BIT[idx]--;
}
