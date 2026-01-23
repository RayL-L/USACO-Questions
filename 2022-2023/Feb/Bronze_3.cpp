//g++ Bronze_3.cpp && ./a.out

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll n, k, cost = 0;
    cin >> n >> k;
    vector<ll> days(n);


    for(ll i = 0; i < n; i++){
        cin >> days[i];

        if(i == 0){
            cost += k+1LL;
        }else{
            cost += min(days[i]-days[i-1], k+1LL);
        }
    }
    cout << cost;

    
    












    return 0;
}