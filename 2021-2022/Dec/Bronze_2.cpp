//g++ Bronze_1.cpp && ./a.out

#include <iostream>
using namespace std;

int main(){

    int n;
    vector<int> p(n), t(n);

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    vector<int> diff(n+2,0);
    for(int i = 0; i < n; i++) diff[i] = p[i] - t[i];

    vector<int> d(n+1);
    for(int i = 0; i < n+1; i++){
        if(diff[i+1]-diff[i-1] > 0){
            d[i] = diff[i+1] - diff[i];
        }
    }

    int ans = 0;
    for(int x : d) ans += x;
    cout << ans;




    return 0;
}