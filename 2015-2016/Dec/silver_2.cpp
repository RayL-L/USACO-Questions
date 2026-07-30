#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){

    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; cin >> n;

    vector<int> b, e(n);

    for(int i = 0; i < n; i++) cin >> e[i];
    for(int i = 1; i <= 2*n; i++){
        if(find(begin(e), end(e), i) == e.end()){
            b.push_back(i);
        }
    }

    sort(b.begin(), b.end(), greater<int>());
    sort(e.begin(), e.end(), greater<int>());

    int ib = 0, ie = 0;
    int ans = 0;
    while(ib < n && ie <n){
        if(b[ib] > e[ie]){
            ans++;
            ib++;
        }
        ie++;

    }

    cout << ans << endl;







    return 0;
}