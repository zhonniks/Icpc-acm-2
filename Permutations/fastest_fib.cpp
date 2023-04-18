#include <bits/stdc++.h>
using namespace std;
const long MOD = 1e9 + 7;
#define ll long long

map<long , long> F;

ll f( ll n) {
    if (F.count(n)) return F[n];
    ll k = n / 2;
    if( n % 2 == 0) {
        return F[n] = (f(k) * f(k) + f(k - 1)*f(k - 1)) % MOD;
    }
    else {
        return F[n] = (f(k) * f(k + 1) + f(k - 1)* f(k)) % MOD;
    }
}

int main() {
    ll n;
    cin >> n;
    F[0] = F[1] = 1;
    cout << ( n == 0 ? 0 : f(n - 1));

    return 0;
}
