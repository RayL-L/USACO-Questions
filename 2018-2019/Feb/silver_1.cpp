//g++ silver_1.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;



int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n; cin >> n;
    vector<int> cow(n);
    for(int i = 0; i < n; i++) cin >> cow[i];

    sort(cow.begin(), cow.end());

    int mi = 0, ma;
    if(cow[n-2]-cow[0] == n-2 && cow[n-1]-cow[n-2] >= 3 || cow[n-1]-cow[1] == n-2 && cow[1]-cow[0] >= 3) mi = 2;
    else{
        for(int l = 0; l < n; l++){
            int r = l, temp = 0;
            while(cow[r] < cow[l]+n && r < n){
                temp++;
                r++;
            }
            mi = max(mi, temp);
        }
        mi = n-mi;
    }

    ma = max(cow[n-2]-cow[0], cow[n-1]-cow[1]) - (n-2);

    cout << mi << endl << ma;







    return 0;
}