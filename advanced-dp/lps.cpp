// LPS Largest Palindromic Subsequence
#include <bits/stdc++.h>
using namespace std;
int  l[100][100];
string s;
int lps(int i , int j) {
    if (l[i][j] == -1) {
        if (s[i] == s[j]) {
            if (i + 1 == j) l[i][j] = 2;
            else
                l[i][j] = lps(i + 1 , j - 1 ) + 2; 
        }
        else 
            l[i][j] = max(lps(i + 1,j),lps(i,j - 1));
    }
    return l[i][j];
}

int main() {
    cin >> s;
    int n = s.size();
  
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < n ;j++) {
            if (i == j) l[i][j] = 1;
            else if (i > j) l[i][j] = 0;
            else l[i][j] = -1;
        }
    }
    cout << lps(0, n - 1);
  
    return 0;
}
