#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int N = 200001;
vector<pair<int,int> > g[N];
vector<bool>was;
vector<int> color; 
int ti ,tin[N] , fup[N]; 
vector <bool> bridge;
int component ;

void dfs1(int v ,int p = -1) {
    was[v] = true;
    tin[v] = fup[v] = ti++;
    for (auto u: g[v]) {
        int to = u.first;
        if (to == p) 
                 continue;
        if (was[to]) {
            fup[v] = min (fup[v],tin[to]);
        }
        else {
            dfs1(to,v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                bridge[u.second] = true;
            }
        }
    }
}

void dfs2(int v , int colors) {
    color[v] = colors;

    for (auto u : g[v]) {
        int to = u.first;
        if (color[to] == -1 && !bridge[u.second]) {
            dfs2(to,colors);
        }
    }
}

int main() {
    int n , m ;
    cin >> n >> m;
    was.resize(n,false);
    bridge.resize(m,false);
    color.resize(n,-1);
    for (int e = 1; e <= m ; e++) {
        int a,b;
        cin >> a >> b;
        --a , --b;
        g[a].push_back(make_pair(b , e));
        g[b].push_back(make_pair(a , e));
    }

    ti = 0;

    for (int v = 0 ; v < n; v++) {
        if(!was[v]) 
            dfs1(v);
    }
    component = 0;
    for (int v = 0; v < n ; v++) {
        if (color[v] == -1) {
            component++;
            dfs2(v,component);
        }
    }
    cout << component << "\n";

    for (int c : color)
        cout << c << " ";
    return 0;
}
