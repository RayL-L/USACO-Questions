//g++ silver_1.cpp && ./a.out
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, c;
vector<int> cow;

bool check(int x){
    int l = 0, bus = 0;
    while (l < n) {
        int r = l;
        while (r < n && r - l < c && cow[r] - cow[l] <= x) r++;
        bus++;
        l = r;
    }
    return bus <= m;
}


int main(){

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;
    cow.resize(n);
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }

    sort(begin(cow), end(cow));

    int l = 0, r = cow[n-1]-cow[0];

    while(l < r){
        int mid = l+(r-l)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l;
    

    return 0;
}