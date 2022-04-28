#include<bits/stdc++.h>
using namespace std;

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 0;
}

int main() {
    int p = 2267, q = 103, e0 = 2, e1, e2, d = 30, r = 11, M = 1000;
    /*cout << "\nEnter the values of p, e1, d, and r:\n";
    cin >> p >> e1 >> d >> r;
    cout << "\nEnter the message:\n";
    cin >> M;*/
    cout << "\nSigning:\n";
    int S1, S2, exp;
    exp = (p - 1) / q;
    e1 = e0;
    for(int i = 0; i < exp; ++i) {
        e1 = e1 * e0;
        e1 = e1 % p;
    }
    e2 = e1;
    for(int i = 1; i < r; ++i) {
        e2 = (e2 * e1) % p;
    }
    S1 = stoi(to_string(M) + to_string(e2));
    S1 = rand() % S1;
    S2 = (r + (d * S1)) % p;    
    cout << "\nThe signatures are:\n" << "S1 = " << S1 << ", S2 = " << S2 << endl;
    cout << "\nVerifying:\n";
    int V, a, b;
    a = e1;
    for(int i = 0; i < S2; ++i){
        a = a * e1;
        a = a % p;
    }
    b = e2;
    for(int i = 0; i < S1; ++i) {
        b = b * e2;
        b = b % p;
    }
    b = modInverse(b, p);
    int c = (a * b) % p;
    V = stoi(to_string(M) + to_string(c));
    cout << "\nV = " << V;
    cout << "\nIf h(V) is congruent to h(S1) then the message is accepted, otherwise rejected"; 
    return 0;
}