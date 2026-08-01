#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
using ll = long long;

int n, q, ans;
ll k;

vector<vector<pair<int, ll>>> adj;
vector<bool> visited;

void dfs(int node){
    visited[node] = true;
    for(pair<int, ll> p : adj[node]){
        if(!visited[p.first] && p.second >= k){
            ans++;
            dfs(p.first);
        }
    }
}


int main(){
    freopen("mootube.in", "r", stdin);freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b; ll r; cin >> a >> b >> r;
        adj[a].push_back({b,r});
        adj[b].push_back({a,r});
    }

    for(int i = 0; i < q; i++){
        int v; cin >> k >> v;

        ans = 0;
        visited = vector<bool>(n+1, false);
        dfs(v);
        cout << ans << endl;
    }





    return 0;
}