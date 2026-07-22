//g++ silver_1.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> farm(n);
    for(int i = 0; i < n; i++) cin >> farm[i];

    sort(farm.begin(), farm.end());

    int l = 0, r = n-1;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;

        cout << upper_bound(farm.begin(), farm.end(), b) - lower_bound(farm.begin(), farm.end(), a) << endl;
    }








    return 0;
}