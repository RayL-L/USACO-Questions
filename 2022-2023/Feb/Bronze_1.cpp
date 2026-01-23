//g++ Bronze_1.cpp && ./a.out

#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;


int main(){
    
    ll n, t;
    cin >> n >> t;

    ll total = 0, remain = 0, last_d = 0;
    for(ll i = 0; i < n; i++){
        ll d, b;
        cin >> d >> b;

        total += b;
        remain -= d-last_d;
        last_d = d;
        remain = max(0LL, remain) + b;
    }


    ll d = t + 1, b = 0;
    remain -= (d - last_d);
    remain = max(0LL, remain) + b;
    cout << (total - remain);

    return 0;
}