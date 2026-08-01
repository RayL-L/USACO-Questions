#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> open;
int cnt;

void dfs(int a){
    visited[a] = true;
    for(int x : adj[a]){
        if(!visited[x] && open[x]){
            cnt++;
            dfs(x);
        }
    }
}

int main(){

    freopen("closing.in", "r", stdin);freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    adj.resize(n+1);
    open.assign(n+1, false);
    

    for(int i = 0; i < m; i++){
        pair<int, int> p; cin >> p.first >> p.second;
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    vector<int> order(n);
    for(int &i : order) cin >> i;
    reverse(order.begin(), order.end());

    vector<string> ans;
    for(int i = 0; i < n; i++){
        visited.assign(n+1, false);
        open[order[i]] = true;
        cnt = 0;
        dfs(order[i]);
        if(cnt == i) ans.push_back("YES");
        else ans.push_back("NO");
    }

    // for(vector<int> v : adj){
    //     for(int x : v) cout << x;
    //     cout << endl;
    // }

    reverse(ans.begin(), ans.end());

    for(string s : ans) cout << s << endl;


    return 0;
}