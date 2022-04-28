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
    int p, e1, e2, d, r, M;
    cout << "\nEnter the values of p, e1, d, and r:\n";
    cin >> p >> e1 >> d >> r;
    cout << "\nEnter the message:\n";
    cin >> M;
    cout << "\nSigning:\n";
    int S1, S2;
    e2 = e1;
    for(int i = 1; i < d; ++i) {
        e2 = (e2 * e1) % p;
    }
    S1 = e1;
    for(int i = 1; i < r; ++i) {
        S1 = (S1 * e1);
        S1 = S1 % p;
    }
    int x = (d * S1) % (p - 1);
    S2 = M - x;
    if(S2 < 0) {
        S2 = (p - 1) + S2;
    }
    S2 = S2 * modInverse(r, p - 1);
    S2 = S2 % (p - 1);
    cout << "\nThe signatures are:\n" << "S1 = " << S1 << ", S2 = " << S2 << endl;
    cout << "\nVerifying:\n";
    int V1, V2;
    V1 = e1;
    for(int i = 1; i < M; ++i){
        V1 = V1 * e1;
        V1 = V1 % p;
    }
    cout << "\nV1 = " << V1;
    int a = d, b = S1;
    for(int i = 1; i < S1; ++i) {
        a = a * d;
        if(a > p) {
            a = a % p;
        }
    }
    for(int i = 1; i < S2; ++i) {
        b = b * S1;
        if(b > p) {
            b = b % p;
        }
    }
    V2 = (a * b) % p;
    cout << "\nV2 = " << V2;
    if(V1 != V2) {
        cout << "\nSince V1 and V2 are not congruent, the receiver rejects the message";
    }else {
        cout << "\nMessage Accepted";
    }
    return 0;
}