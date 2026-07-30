#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


int main(){

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);


    int n, m, r; cin >> n >> m >> r;

    vector<int> cows(n), rent(r);
    vector<pair<int, int>> milk(m);

    for(int &i : cows) cin >> i;
    for(pair<int, int> &p : milk) cin >> p.first >> p.second;
    for(int &i : rent) cin >> i;

    sort(begin(cows), end(cows), greater<int>());
    sort(begin(rent), end(rent), greater<int>());
    sort(begin(milk), end(milk), [](pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    });

    long long ans = 0;


    vector<long long> mp(n+1, 0), rp(n+1, 0);
    int milk_i = 0;
    for(int i = 1; i <= n; i++){
        mp[i] = mp[i-1];
        int remaining = cows[i-1];
        while(remaining > 0 && milk_i < m){
            int take = min(remaining, milk[milk_i].first);
            mp[i] += (long long)take * milk[milk_i].second;
            remaining -= take;
            milk[milk_i].first -= take;
            if(milk[milk_i].first <= 0) milk_i++;
        }
    }

    for(int i = 1; i <= n && i <=r; i++){
        rp[i] = rp[i-1] + rent[i-1];
    }
    reverse(rp.begin(), rp.end());

    for(int i = 0; i <= n; i++){
        ans = max(ans, (long long)rp[i] + mp[i]);
        //cout << rp[i] << " ";
    }

    cout << ans;








    return 0;
}