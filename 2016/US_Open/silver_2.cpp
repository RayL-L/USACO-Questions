//g++ silver_2.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);


    int n, k; cin >> n >> k;
    vector<int> diamond(n), len(n), best(n);

    for(int i = 0; i < n; i++) cin >> diamond[i];

    sort(diamond.begin(), diamond.end());
    int r = 0;

    for(int l = 0; l < n; l++){
        if(r < l) r = l;
        while(r < n && diamond[r] - diamond[l] <= k){
            r++;
        }
        len[l] = r-l;
    }

    best[n-1] = len[n-1];

    for(int i = n-2; i >= 0; i--){
        best[i] = max(best[i+1], len[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, len[i] + best[len[i]+i]);
    }
    cout << ans;






    return 0;
}