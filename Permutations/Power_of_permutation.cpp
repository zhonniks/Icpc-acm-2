//степень перестановки + нахождение циклов перестановки
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

vector<int> per_len;

void findCycles(int p[] , int n) {
    vector<bool> used(n); // visited positions
    for( int i = 1 ; i <= n ; i++) {
        if(!used[i]) {
            int j = i;
            vector<int>cycle;

            while(!used[j]) {
                cycle.push_back(p[j]);
                used[j] = true;
                j = p[j];
            }
            per_len.pb(cycle.size());
            // for(int i = 0 ; i < cycle.size() ; i++)
            //     cout << cycle[i] << " ";
            // cout << "\n";
        }
    }
}

int findlcm() {
    int ans = per_len[0];

    for(int i = 1; i < per_len.size() ; i++) {
        ans = (( (per_len[i] * ans)) / (__gcd(per_len[i] , ans) ) );
    }
    return ans;
}

int main() {
    int n;
    cin >> n ;
    int p[n];
    for(int i = 1 ; i <= n ; i++) 
        cin >> p[i];

    findCycles(p , n);
    cout << findlcm();
    return 0;
}
