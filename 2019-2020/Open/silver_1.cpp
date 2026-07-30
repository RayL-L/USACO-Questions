#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<pair<ll, ll>> farm;

bool check(ll d){
    ll cnt = 1, pos = farm[0].first;
    int i = 0;
    while (cnt < n) {
        ll next = pos + d;
        while (i < m && farm[i].second < next) i++;
        if (i == m) return false;
        pos = max(next, farm[i].first);
        cnt++;
    }
    return true;
}

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> n >> m;
    farm.resize(m);
    for(int i = 0; i < m; i++){
        cin >> farm[i].first >> farm[i].second;
    }

    sort(begin(farm), end(farm), [](pair<ll,ll> a, pair<ll, ll> b){
        return a.first < b.first;
    });

    ll l = 0, r = farm[m-1].second;
    while(l < r){
        ll mid = l + (r-l+1)/2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l;

    return 0;
}