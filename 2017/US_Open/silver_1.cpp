//g++ silver_1.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, long long>> cow(n);

    for(int i = 0; i < n; i++){
        long long count;
        int time;
        cin >> count >> time;

        cow[i] = {time, count};
    }

    sort(cow.begin(), cow.end());

    int ans = 0;
    int l = 0, r = n - 1;

    while(l < r){
        ans = max(ans, cow[l].first + cow[r].first);

        long long paired = min(cow[l].second, cow[r].second);

        cow[l].second -= paired;
        cow[r].second -= paired;

        if(cow[l].second == 0) l++;
        if(cow[r].second == 0) r--;
    }

    cout << ans;

    return 0;
}