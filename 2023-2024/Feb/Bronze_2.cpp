//g++ Bronze_2.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){


    ll n, m, sum = 0;
    string s;
    cin >> n >> m >> s;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    for(ll x : a) sum += x;

    size_t pos = s.find("LR");
    ll st = (ll)pos+1;

    ll curr = 0, lost = 0;

    for(ll i = 0; i < n; i++){
        curr += a[(st+i)%n];
        if(s[(st+i)%n] != s[(st+i+1)%n]){
            if(s[(st+i)%n] == 'R'){
                curr -= a[(st+i)%n];
                i++;
            }
            lost += min(curr, m);
            curr = 0;
        }
    }

    cout << (sum - lost);












    // a_1 = a;

    // for(ll x : a) sum += x;

    // for(ll j = 0; j < m; j++){
    //     for(ll i = 0; i < n; i++){
    //         if(a[i] > 0){
    //             a[i]--;
    //             if(s[i] == 'R'){
    //                 if(i != n-1){
    //                     a[i+1]++;
    //                 }else{
    //                     a[0]++;
    //                 }
                    
    //             }else{
    //                 if(i != 0){
    //                     a[i-1]++;
    //                 }else{
    //                     a[n-1]++;
    //                 }
                    
    //             }
    //         }
    //     }
    // }

    // for (ll i = 0; i < n; i++){
    //     a[i] -= a_1[i];
    //     if(a[i]>0) sum_1 += a[i];
    // }

    

    // cout << (sum - sum_1);
    



    

















    return 0;
}