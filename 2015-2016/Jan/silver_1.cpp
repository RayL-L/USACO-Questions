#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, k;
vector<int> haybale;

bool check(int range){
    range *= 2;
    int l = 0;
    int need = 0;
    while(l < n){
        int r = l;
        while(r < n && haybale[l]+range >= haybale[r]) r++;
        need++;
        l = r;
    }
    return need <= k;
}

int main(){
    ifstream cin("angry.in");
    ofstream cout("angry.out");

    cin >> n >> k;

    haybale.resize(n);
    for(int i = 0; i < n; i++) cin >> haybale[i];

    sort(haybale.begin(), haybale.end());

    int l = 0, r = haybale[n-1] - haybale[0];

    while(l < r){
        int mid = l + (r-l)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l;

    return 0;
}