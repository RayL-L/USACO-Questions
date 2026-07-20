//g++ Bronze_1.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t, k; cin >> t >> k;

    if(k == 0){
        for(int i = 0; i < t; i++) cout << "YES" << endl;
        return 0;
    }else{
        for(int i = 0; i < t; i++){
            int n; cin >> n;
            string s; cin >> s;

            string ans(n, ' ');
            int numO = 0;

            for(int i = n - 1; i >= 0; i--){
                char c = s[i];
                if(numO % 2 == 0){
                    ans[i] = s[i];
                }else{
                    if(s[i] == 'O') ans[i] = 'M';
                    else ans[i] = 'O';
                }
                if(ans[i] == 'O') numO++;
            }

            cout << "YES" << endl << ans << endl;
        }
    }















    return 0;
}