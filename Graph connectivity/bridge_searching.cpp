#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int N = 200001;
vector<pair<int,int> > g[N];
int ti ,tin[N] , fup[N]; 
vector <int> bridge;
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
                bridge.push_back(u.second);
            }
        }
    }
}
int main() {
    int n , m ;
    cin >> n >> m;
    was.resize(n,false);
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
    cout << bridge.size() << "\n";
    sort(bridge.begin(),bridge.end());

    for (int i = 0 ; i < bridge.size(); i++) {
        cout << bridge[i] << " ";
    }
    return 0;
}
