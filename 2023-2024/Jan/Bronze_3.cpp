//g++ Bronze_3.cpp && ./a.out

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int power;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        power = 1;
        if(a[i] == 0){
            continue;
        }else{
            int times = llabs(a[i]);
            int dir;
            ans += times;
            if(a[i] > 0){
                dir = -1;
            }else{
                dir = 1;
            }

            for(int j = i; j < n; j++){
                a[j] += dir * times * power;
                power++;
            }


            
        }
    }

    cout << ans;

















    return 0;
}