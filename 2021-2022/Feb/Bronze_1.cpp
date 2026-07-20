//g++ Bronze_1.cpp && ./a.out

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t; cin >> t;
    for(int ca = 0; ca < t; ca++){
        int n; cin >> n;
        int mx = 0;

        vector<int> a(n);
        vector<int> b;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int temp = 0;
        for(int i = 0; i < n; i++){
            temp += a[i];
            if(temp >= mx){
                b.push_back(temp);
                mx = temp;
                temp = 0;
            }
        }

        int x = b[0];
        int ans = n - b.size();

        for(int y : b){
            if(y != x){
                ans = ans + b.size()-1;
                break;
            }
        }


        
        cout << ans << endl;


    }



    return 0;
}