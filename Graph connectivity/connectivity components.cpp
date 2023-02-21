#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
vector<int> g[N];
vector <int> comp(N); // comp[v] - > номер комнонента связности 
int num = 0; // номер компонента связности 

int dfs(int v ){
    comp[v] = num;
    for (int u : g[v]) {
        if (comp[u] == 0) 
            dfs(u);
    }
}

int main() {
    int n , m ;
    cin >> n >> m;
    for (int e = 1; e <= m ; e++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int v = 1 ; v <= n ; v++) comp[v] = 0;
    for (int v = 1; v <= n ; v++) {
        if (comp[v] == 0) {
            ++num;
            dfs(v);
        }
    }
    cout << num  << " ";
    return 0;
}
