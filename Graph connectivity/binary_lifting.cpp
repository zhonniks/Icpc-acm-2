//binary lifting , метод двоичного подъема
#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int up[N][LOG]; // 2^j -th ancestor of i-th vertex
//  N = 19 : 10011 => 16 + 2 + 1

void preprocess() {
    for (int v = 0 ; v <= N - 1; ++v) {
        up[v][0] = parent[v];
    }

    for (int j = 1 ; j <= LOG - 1; ++j) {
        for (int v = 0 ; v <= N - 1; ++v) 
            up[v][j] = up[ up[v][j - 1] ][j - 1];
    }
}

int main() {
    preprocess();  // O(N * log(N)) - complexity
    return 0;
}
