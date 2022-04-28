#include<bits/stdc++.h>
using namespace std;

vector<int> xcord, ycord;

void ellipticCurve_points(int p, int a, int b) {
    int x = 0, w;
    while(x < p) {
        w = (pow(x, 3) + (a * x) + b);
        w = w % p;
        if(floor(sqrt(w)) == sqrt(w) || ceil(sqrt(w)) == sqrt(w)) {
            int y = sqrt(w);
            if(y < (p - y)) {
                xcord.push_back(x);
                ycord.push_back(y);
                xcord.push_back(x);
                ycord.push_back(p - y);
            } else {
                xcord.push_back(x);
                ycord.push_back(p - y);
                xcord.push_back(x);
                ycord.push_back(y);
            }
           
        }
        ++x;
    }
}

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
    return 0;
}

int main() {
    int a, b, p, x1, y1, x2, y2, x3, y3, m, n;
    cout << "Enter a, b, p:";
    cin >> a >> b >> p;
    cout << "Enter P and Q:";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Adding P + Q:";
    m =  ((y2 - y1) * modInverse((x2 - x1), p)) % p;
    x3 = ((m * m) - x1 - x2) % p;
    y3 = (m * (x1 - x3) - y1) % p;
    if(y3 < 0) {
        cout << "\nx = " << x3 << " y = " << p + y3;
    } else {
        cout << "\nx = " << x3 << " y = " << y3;
    }
    cout << "\nnP:";
    cout << "\nEnter n:";
    cin >> n;
    ellipticCurve_points(p, a, b);
    int point;
    for(int i = 0; i < xcord.size(); ++i) {
        if(xcord[i] == x1 && ycord[i] == y1) {
            point = i;
        } 
    }
    cout << "\nx = " << xcord[(point + n)%xcord.size()] << " y = " << ycord[(point + n)%xcord.size()];
    cout << "\nInverse of P:";
    cout << "\nx = " << x1 << " y = " << p - y1;
    return 0;
}