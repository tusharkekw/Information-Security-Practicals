#include<bits/stdc++.h>
using namespace std;

void ellipticCurve_points(int p, int a, int b) {
    int x = 0, w;
    while(x < p) {
        cout << "\nwhen x = " << x <<":\n";
        w = (pow(x, 3) + (a * x) + b);
        w = w % p;
        if(floor(sqrt(w)) == sqrt(w) || ceil(sqrt(w)) == sqrt(w)) {
            int y = sqrt(w);
            cout << "(" << x << ", " << y << ") and (" << x << ", " << 
            (p - y) % p << ") lie on the curve\n";   
        } else {
            cout << "the points do not lie on the curve\n";
        }
        ++x;
    }
} 

int main() {
    int p, a, b; 
    cout << "Enter a prime number:";
    cin >> p;
    cout << "\nEnter a and b:";
    cin >> a >> b; 
    cout << "\nFinding points on the curve:\n";
    ellipticCurve_points(p, a, b);
    return 0;
}