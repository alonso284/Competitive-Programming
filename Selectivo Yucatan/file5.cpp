#include <iostream>

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <cctype>
#include <cmath>
#include <ctgmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>

using namespace std;
// g++ OMI.cpp -std=c++11

string puente;
int DP[5001][2], n;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> puente ;

    // puente = '_' + puente;
    for (int i = 0; i < n; ++i) // fin
    {
        for (int j = n-1; j >= 0 ; --j) // ini
        {
            if(j >= i) DP[j][i%2] = 0;
            else if(puente[j] == puente[i]) DP[j][i%2] = DP[j+1][(i-1)%2];
            else DP[j][i%2] = min(DP[j+1][i%2], DP[j][(i-1)%2]) + 1;
            // cout << DP[j][i%2] << '(' << puente[j] << ',' << puente[i] << ')' << ' ';
        }
        // cout << endl;
    }

    cout << DP[0][(n-1)%2];

    return 0;
}