//g++ Bronze_2.cpp && ./a.out

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int num = 0;
        string cow;
        int n, k; cin >> n >> k >> cow;
        int pos_g = n+10, pos_h = n+10;
        vector<char> grass(n, '.');


        for(int i = 0; i < n; i++){
            char currCow = cow[i];


            if(currCow == 'G'){
                if(abs(i-pos_g) <= k) continue;
                int p = min(i+k, n-1);
                while(p >= i-k && grass[p] != '.') p--;
                grass[p] = 'G';
                pos_g = p;
                num++;
            }else{
                if(abs(i-pos_h) <= k) continue;
                int p = min(i+k, n-1);
                while(p >= i-k && grass[p] != '.') p--;
                grass[p] = 'H';
                pos_h = p;
                num++;
            }


        }
            

        cout << num << "\n";
        for(char c : grass) cout << c;
        cout << "\n";

    }

















    return 0;
}