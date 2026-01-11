//g++ Question_3.cpp && ./a.out

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    
    vector<int> r(q);
    vector<int> c(q);
    vector<int> v(q);
    int mx = 0;
    

    for(int i = 0; i < q; i++){
        cin >> r[i] >> c[i] >> v[i];
    }


    for(int i = 0; i < q; i++){
        
        if(i == 0){
            mx = max(v[i], mx);
            cout << mx << "\n";
        }else{
            int nmx = v[i];
            for(int j = i-1; j >= 0; j--){
                bool isSame = r[i] == r[j] && c[i]==c[j];
                int dis_r = abs(r[i]-r[j]);
                int dis_c = abs(c[i]-c[j]);

                if(dis_r < k && dis_c < k && !isSame){
                    nmx += v[j];
                }
                mx = max(nmx, mx);
            }
            

            cout << mx << "\n";
        }

    }

    
    
    return 0;
}