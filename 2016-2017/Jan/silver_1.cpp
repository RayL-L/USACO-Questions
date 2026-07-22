#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, t;
vector<int> cow;

bool check(int s){
    priority_queue<int, vector<int>, greater<int>> pq;
    long long endTime = 0;

    for(int i = 0; i < s; i++){
        pq.push(cow[i]);
        endTime = max(endTime, (long long)cow[i]);
    }
    for(int i = s; i < n; i++){
        int start  = pq.top(); pq.pop();
        int finish = start + cow[i];
        pq.push(finish);
        endTime = max(endTime, (long long)finish);
    }
    return endTime <= t;
}

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> t;
    cow.resize(n);
    for(int i = 0; i < n; i++) cin >> cow[i];

    int lo = 1, hi = n, ans = n;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){ ans = mid; hi = mid - 1; }
        else          { lo = mid + 1; }
    }
    cout << ans << "\n";
    return 0;
}