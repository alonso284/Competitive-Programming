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

int funcionDeSanty(int num){
    int MIN = 10, MAX = -1;
    for (int i = pow(10, int(log10(num)) + 1); i > 1; i/=10)
    {
        int here= (num%i)/(i/10);
        MIN = min(here, MIN);
        MAX = max(here, MAX);
    }
    return num + MIN*MAX;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Santy, K;
    cin >> Santy >> K;
    for (int i = 0; i < K-1; ++i)
    {
        if(funcionDeSanty(Santy) == Santy) break;
        Santy = funcionDeSanty(Santy);
    }

    cout << Santy;

    return 0;
}