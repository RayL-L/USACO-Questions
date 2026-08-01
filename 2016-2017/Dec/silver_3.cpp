#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct cow{
    int x, y, p;
};
int n, ans = 0;
vector<vector<int>> adj;
vector<cow> cows;
vector<bool> visited;
int cnt;


void dfs(int a){
    visited[a] = true;
    for(int x : adj[a]){
        if(!visited[x]){
            cnt++;
            dfs(x);
        }
    }
}



int main(){
    freopen("moocast.in", "r", stdin);freopen("moocast.out", "w", stdout);
    cin >> n;
    adj.resize(n+1);
    cows.resize(n);
    for(cow &c : cows) cin >> c.x >> c.y >> c.p;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            long long d = (cows[i].x-cows[j].x)*(cows[i].x-cows[j].x) + (cows[i].y-cows[j].y)*(cows[i].y-cows[j].y);
            // cout << d << " ";
            if(d <= (long long)cows[i].p * cows[i].p) adj[i+1].push_back(j+1);
            if(d <= (long long)cows[j].p * cows[j].p) adj[j+1].push_back(i+1);
        }
    }

    // for(vector<int> v : adj){
    //     for(int x : v) cout << x;
    //     cout << endl;
    // }


    for(int i = 1; i <= n; i++){
        visited.assign(n+1, false);
        cnt = 1;
        dfs(i);
        ans = max(ans, cnt);
    }

    cout << ans;



    return 0;
}