#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;

int main() {
    int l;
    cin >> l ; // dlina bruska
    int n ;
    cin >> n;
    deque <int> c;

    for (int i = 0; i < n ; i++) {
        int a;
        cin >> a;
        c.push_back(a);
    }
    n += 2;
    c.push_front(0); //chobi ne vihodil za massiv 
    c.push_back(l);

    int dp[n][n];

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)
            dp[i][j] = 0;
    }

    for (int i = 1 ; i < n ; i++) { // hodim po srubam 
        for (int j = i - 2 ; j > -1 ; j -= 1 ) { // rasbivaem brusok dlini[0,i - 1] na j kuskov
            dp[j][i] = N;
            for (int k = j + 1 ; k < i ; k++) // zapolnyam dp stoimostiyu
                dp[j][i] = min(dp[j][i], dp[j][k] + dp[k][i]); 
        dp[j][i] += c[i] - c[j];
        }
    }

    cout << dp[0][n - 1];
    return 0;
}
