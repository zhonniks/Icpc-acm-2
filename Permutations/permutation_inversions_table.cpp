//нахождение таблицы инверсий перестановки
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

void inversion(int p[] , int n) {  // O(n^2)
    vector<int> T(n,0);

    for(int i = 1 ; i <= n ; i++) {
        for(int j = i ; j >= 1 ; j--) {
            if(p[j] > p[i])
                T[p[i]]++;
        }
    }

    for (int i = 1; i <= n ; i++) 
        cout << T[p[i]] << " ";
}

int main() {
    int n;
    cin >> n;
    int p[n];
    for(int i = 1 ; i <= n ; i++)
        cin >> p[i];
    inversion(p , n);

    return 0;
}
