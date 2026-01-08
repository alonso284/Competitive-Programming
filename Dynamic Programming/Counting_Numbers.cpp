#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int64_t dp[20][10][2][2];
bool vis[20][10][2][2];

string n;
int64_t DP(int curr, char prev_digit, bool leading_zero, bool tight){
	if(curr == n.size()) return 1;

	int64_t &ans = dp[curr][prev_digit-'0'][leading_zero][tight];
	bool &passed = vis[curr][prev_digit-'0'][leading_zero][tight];
	if(passed) return ans;
	passed = true;
	for(char next_digit = '0'; next_digit <= (tight ? n[curr] : '9'); next_digit++)
		if(prev_digit != next_digit || (next_digit == '0' && leading_zero)){
			int new_tight = tight && (n[curr] == next_digit);
			int new_leading_zero = leading_zero && (next_digit == '0');
			ans += DP(curr+1, next_digit, new_leading_zero, new_tight);
		}
	return ans;
}

void reset(){
	for(int i = 0; i < 20; i++)
	for(int j = 0; j < 10; j++)
	for(int k = 0; k < 2; k++)
	for(int l = 0; l < 2; l++)
		dp[i][j][k][l] = vis[i][j][k][l] = false;
}


int main(){
	
	int64_t ans = 0;
	int64_t temp; cin >> temp;
	if(temp){
		temp--; n = to_string(temp);
		ans -= DP(0, '0', true, true);
	}

	reset();
	cin >> n;
	ans += DP(0, '0', true, true);
	cout << ans << endl;

}
