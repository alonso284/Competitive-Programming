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


int64_t N, K, A[100000], B[100000], posibilidades[100000], digits, result = 1;

int64_t calcularPosibilidades(int64_t i){
    if(B[i] == 0) return (digits*10 - 1)/A[i] - (digits*(B[i]+1) - 1)/A[i];
    return (digits*10 - 1)/A[i] - (digits*(B[i]+1) - 1)/A[i] + (digits*(B[i]) - 1)/A[i] + 1;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    digits = pow(10, K-1);

    for (int64_t i = 0; i < N/K; ++i)
        cin >> A[i];
    
    for (int64_t i = 0; i < N/K; ++i)
        cin >> B[i];

    for (int64_t i = 0; i < N/K; ++i)
        posibilidades[i] = calcularPosibilidades(i);

    for (int64_t i = 0; i < N/K; ++i)
        result = (result*posibilidades[i])%1000000007;
    cout << result;


    


    return 0;
}