//g++ Bronze_3.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll T, n;
//     cin >> T;
//     for(int i = 0; i < T; i++){
//         cin >> n;

//         if(n == 1){
//             cout << 0 << "\n";
//             continue;
//         }

//         vector<ll> h(n), a(n), t(n), sh(n,0), sa(n,0);
//         for(ll i = 0; i < n; i++) cin >> h[i];
//         for(ll i = 0; i < n; i++) cin >> a[i];
//         for(ll i = 0; i < n; i++) cin >> t[i];

//         for(ll i = 0; i < n; i++){  //sort
//             sh[t[i]] = h[i];
//             sa[t[i]] = a[i];
//             // x > (sh[i+1] - sh[i]) / (sa[i]-sa[i+1])
//         }

//         vector<ll> x(n-1);
//         for(ll i = 0; i < n-1; i++){

//             if(sa[i] == sa[i+1]){
//                 if(sh[i] <= sh[i+1]){
//                     x[i] = -2;
//                 }else{
//                     x[i] = 0;
//                 }
//             }else{
//                 x[i] = (sh[i+1] - sh[i]) / (sa[i]-sa[i+1]) + 1;
//             }
//         }

//         ll mx = x[0];
        
//         for(ll y: x){

//             if(y < 0){
//                 cout << -1;
//                 break;
//             }else if(y > mx){
//                 cout << -1;
//                 break;
//             }else{
//                 mx = max(mx, y);
//             }
            
//         }

//         cout << mx << "\n";
//     }



// }




// /*
// 6

// 1
// 10
// 1
// 0

// 2
// 7 3
// 8 10
// 1 0

// 2
// 3 6
// 10 8
// 0 1

// 2
// 7 3
// 8 9
// 1 0

// 2
// 7 7
// 8 8
// 0 1

// 2
// 7 3
// 8 8
// 1 0
// */


static ll floor_div(ll a, ll b) {
    // floor(a/b), works for negatives too
    assert(b != 0);
    ll q = a / b, r = a % b;
    if (r != 0 && ((r > 0) != (b > 0))) q--; // adjust toward -inf
    return q;
}

static ll ceil_div(ll a, ll b) {
    // ceil(a/b), works for negatives too
    assert(b != 0);
    ll q = a / b, r = a % b;
    if (r != 0 && ((r > 0) == (b > 0))) q++; // adjust toward +inf
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> h(n), a(n), t(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> t[i];

        if (n == 1) { // always satisfied
            cout << 0 << "\n";
            continue;
        }

        // reorder by rank r = t[i]
        vector<ll> sh(n), sa(n);
        for (int i = 0; i < n; i++) {
            sh[t[i]] = h[i];
            sa[t[i]] = a[i];
        }

        ll L = 0;
        ll R = (1LL<<62); // "infinite" upper bound

        for (int r = 0; r < n - 1; r++) {
            ll A = sa[r] - sa[r+1];
            ll B = sh[r+1] - sh[r];   // need A*d > B

            if (A == 0) {
                // 0*d > B  =>  0 > B  =>  B < 0
                if (!(B < 0)) { L = 1; R = 0; break; } // impossible
            } else if (A > 0) {
                // d > B/A
                ll bound = floor_div(B, A) + 1; // smallest integer strictly greater
                L = max(L, bound);
            } else { // A < 0
                // d < B/A
                ll bound = ceil_div(B, A) - 1; // largest integer strictly less
                R = min(R, bound);
            }
        }

        if (L <= R) cout << L << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}