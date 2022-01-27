#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Actividad por Equipos 01 - PES Enero'
g++ D.cpp -std=c++17
*/

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin >> n){
		vector <string> dict(n);
		unordered_map <string, int> db;

		for(auto& word:dict){
			cin >> word;
			string subWord;
			for(int indx = 0; indx < word.size(); indx++){
				subWord.push_back(word[indx]);
				db[subWord]++;
			}
		}

		double sum = 0;
		for(auto& word:dict){
			string typed, toComplete;
			for(int indx = 0; indx < word.size(); indx++){
				toComplete.push_back(word[indx]);
				sum += (db[typed]!=db[toComplete]);
				typed.push_back(word[indx]);
			}
		}

		cout << fixed << setprecision(2) << sum/n << '\n';
	}

	return 0;
}
