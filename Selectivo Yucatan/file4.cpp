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

int ar[8], size = 8;

bool comparar(int n, int m){
    if(int(log10(n)) == int(log10(m))){
        int digits = pow(10, int(log10(m)) + 1), pos = 1;
        while(digits){
            int temp1 = n/digits%10, temp2 = m/digits%10;
            if(temp1 != temp2){
                // el menor
                if(pos%2)  return temp1 < temp2;
                else return temp1 > temp2;
            }

            digits /= 10;
            pos++;
        }
    }
    return n > m;
}

void mergeSort(int ini, int fin, int ar[]){
    if(ini == fin) return;
    int mitad = (ini+fin)/2;

    mergeSort(ini, mitad, ar);
    mergeSort(mitad+1, fin, ar);

    int apuntador1 = ini;
    int apuntador2 = mitad + 1;
    int arTemp[fin - ini + 1];
    int apuntadorTemp = 0;

    while(apuntador1 <= mitad && apuntador2 <= fin){
        if(comparar( ar[apuntador1], ar[apuntador2])) arTemp[apuntadorTemp++] = ar[apuntador2++];
        else arTemp[apuntadorTemp++] = ar[apuntador1++];
    }

    while(apuntador1 <= mitad) arTemp[apuntadorTemp++] = ar[apuntador1++];
    while(apuntador2 <= fin) arTemp[apuntadorTemp++] = ar[apuntador2++];

    for (int i = 0; i < fin - ini + 1; ++i)
        ar[i+ini] = arTemp[i];

}

void shuffle(int ini, int fin, int ar[]){
    if(ini == fin) return;
    int mitad = (ini+fin)/2;

    int first[mitad-ini+1];
    int second[fin-(mitad+1)+1];

    for (int i = 0; i < fin - ini + 1; ++i)
    {
        if(i%2 == 0) first[i/2] = ar[i + ini];
        else second[i/2] = ar[i + ini];
    }

    for (int i = ini; i <= mitad; ++i)
    ar[i] = first[i-ini];

    for (int i = mitad+1; i <= fin; ++i)
    ar[i] = second[i-(mitad+1)];

    shuffle(ini, mitad, ar);
    shuffle(mitad+1, fin, ar);

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < size; ++i) ar[i] = i+1;
    mergeSort(0, size - 1, ar);
    shuffle(0, size - 1, ar);

    ofstream output;
    output.open("arr");
    output << size << '\n';
    for (int i = 0; i < size; ++i) output << ar[i] << ' ';

    return 0;
}