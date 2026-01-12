//g++ Bronze_2.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s, e, ans, dir;
    cin >> n;
    cin >> s;
    s--;
    e = 1;
    ans = 0;
    dir = 1;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }

    for(int i = 0; i < 5000000 && s >= 0 && s < n; i++){
        if(a[s] == 1){
            if(b[s] <= e && b[s] != -1){
                b[s] = -1;
                ans++;
            }
        }

        if(a[s] == 0){
            dir *= -1;
            e = e + b[s];
        }

        s += dir * e;
    }

    // while(s >= 0 && s < n){
    //     if(a[s] == 1){
    //         if(b[s] <= e && b[s] != -1){
    //             b[s] = -1;
    //             ans++;
    //         }
    //     }

    //     if(a[s] == 0){
    //         dir *= -1;
    //         e = e + b[s];
    //     }

    //     s += dir * e;
    // }

    cout << ans;



    return 0;
}