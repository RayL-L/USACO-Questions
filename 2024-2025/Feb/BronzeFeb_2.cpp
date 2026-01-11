//g++ BronzeFeb_2.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n; 
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    int zero = 0;
    vector<int> freq(5000000, 0);
    vector<int> ans(n+1);

    for(int x : a){
        freq[x]++;
    }

    for(int i = 0; i <= n; i++){
        
        

        if(freq[i] != 0){
            if(freq[i] >= zero){
                ans[i] = freq[i];
            }else{
                ans[i] = zero;
            }
        }else{
            ans[i] = zero;
        }

        if(freq[i] == 0) zero++;


    }

    for(int x : ans){
        cout << x << "\n";
    }

















    return 0;
}