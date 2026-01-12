//g++ Bronze_1.cpp && ./a.out

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> cow(n), cane(m);

    for(int i = 0; i < n; i++) cin >> cow[i];
    for(int i = 0; i < m; i++) cin >> cane[i];

    for(ll x : cane){
        ll prev = 0;
        for(int i = 0; i < n; i++){
            ll h = cow[i];
            ll eat_to = min(x, h);
            if(eat_to > prev){
                ll eaten = eat_to - prev;
                cow[i] += eaten;
                prev = eat_to;
                if(prev >= x) break;
            }
        }
    }

    for(ll x : cow){
        cout << x << "\n";
    }


    return 0;
}