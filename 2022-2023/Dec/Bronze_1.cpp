//g++ Bronze_1.cpp && ./a.out

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ll n, maxTuition = 0; cin >> n;
    vector<ll> tuition(n), best(n), freq(1000000);
    for(ll i = 0; i < n; i++){
        cin >> tuition[i];
        // maxTuition = max(tuition[i], maxTuition);
    }

    sort(tuition.begin(), tuition.end());

    ll tui = 0;
    ll t = 0;

    for(ll i = 0; i < n; i++){

        if(tui < tuition[i]*(n-i)){
            tui = tuition[i]*(n-i);
            t = tuition[i];
        }
    }

    cout << tui << " " << t;










    // vector<ll> freq(maxTuition+1,0);
    // for(ll t = 0; t <= maxTuition; t++){
    //     for(ll cow : tuition){
    //         if(cow >= t){
    //             freq[t]++;
    //         }
    //     }
    // }

    // ll num, wage = 0;
    // for(ll i = 0; i < freq.size(); i++){
    //     ll w = i*freq[i];
    //     wage = max(w, wage);
    // }
    // for(ll i = 0; i < freq.size(); i++){
    //     if(freq[i]*i == wage){
    //         num = i;
    //         break;
    //     }
    // }

    // cout << wage << " " << num;















    return 0;
}