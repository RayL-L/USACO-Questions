#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){

    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int n; cin >> n;
    vector<int> cows(n);
    for(int &i : cows) cin >> i;

    sort(begin(cows), end(cows), greater<int>());

    int ans = 1;

    for(int i = 1; i < n; i++){
        if(cows[i] >= i) ans++;
    }

    cout << ans;











    return 0;
}