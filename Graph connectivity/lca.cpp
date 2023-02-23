#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int LOG ,timer ;
int up[N][100]; // 2^j -th ancestor of i-th vertex
vector<int> tin(N) , tout(N); // время входа и выхода
vector<int> g[N + 1];

void dfs(int v , int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;

    for (int i = 1 ; i <= LOG ; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }

    for (int j = 0 ; j < g[v].size(); ++j) {
        int to = g[v][j];
        if (to != p) 
              dfs(to,v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int v , int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v , int u) {
    if(is_ancestor(v,u)) return v;
    if(is_ancestor(u,v)) return u;
    for (int i = LOG ; i >= 0 ; --i) {
        if (up[v][i] && !is_ancestor(up[v][i],u))
            v = up[v][i];
    }
    return up[v][0];
}

int main() {
    int n, m;            // number of vertices and edges
    cin >> n >> m;
    LOG = 1;
    while ((1 << LOG) <= n)  LOG++;
    for (int i = 0 ; i < m ; i++) {
        int a ,b;
        cin >> a>> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}
