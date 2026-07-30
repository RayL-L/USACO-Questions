#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n; cin >> n;
    int ans = INT_MAX;
    int total = 0;

    vector<pair<int, int>> cows(n+1);
    cows[0] = {0, 0};
    for(int i = 1; i <= n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(begin(cows), end(cows), [](pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first;
    });
    cows.push_back({INT_MAX, INT_MAX});

    int lend = -1, l = -1, rend = -1;
    for(int i = 1; i <= n; i++){

        lend = max(cows[i].first, cows[i-1].second);
        rend = min(cows[i].second, cows[i+1].first);
        l = max(l, lend);
        total += max(0, cows[i].second - l);
        ans = min(max(0,rend-lend), ans);
    }


    cout << total - ans;








    return 0;
}