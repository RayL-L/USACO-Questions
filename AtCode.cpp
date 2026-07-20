//g++ AtCode.cpp && ./a.out
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    
    int n, m; cin >> n >> m;

    vector<int> a(n), b(n-1), c(n);
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1;i++){
        cin >> b[i];
    }
    c[0] = a[0];

    for(int i = 0;i < n-1; i++){
        int x = (c[i] + a[i+1])%m;
        x = abs(x - b[i]);
        if(x > 0){
            ans++;
        }
        c[i+1] = a[i]+x;
    }

    cout << ans;



    return 0;
}