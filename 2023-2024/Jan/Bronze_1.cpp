//g++ Bronze_1.cpp && ./a.out

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<int>& h){

    vector<int> ans;
    vector<int> final;
    for(int i = 2; i < n; i++){
        if(h[i]==h[i-1] || h[i]==h[i-2]) ans.push_back(h[i]);
        if(h[i-1]==h[i-2]) ans.push_back(h[i-1]);
    }
    set<int> a(ans.begin(), ans.end());
    for(int x : a) final.push_back(x);
    return final;
}


int main(){

    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }

        if(n == 2){
            if(h[0]==h[1]){
                cout << h[0];
            }else{
                cout << -1;
            }
        }else{
            vector<int> ans = solution(n, h);

            if(ans.empty()) cout << -1;

            for(int i = 0; i < ans.size(); i++){
                if(i) cout << " ";
                cout << ans[i];
            }
        }

        cout << "\n";

    }

    return 0;
}