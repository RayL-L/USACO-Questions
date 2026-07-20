//g++ AtCoder.cpp && ./a.out
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t; cin >> t;


    for(int i = 0; i < t; i++){
        bool aWin = true;
        bool picked = false;
        int n; cin >> n;
        vector<int> game(n), state(n,0);
        for(int i = 0;i < n; i++) cin >> game[i];

        for(int i = 0; i < n-1 && aWin; i++){
            if(game[i] && game[i+1]){
                game[i]++; 
                game[i+1]++;
                aWin = false;
            }
        }
        if(aWin){
            cout << "Alice" << endl;
            continue;
        }
        if(game[0]==1){
            game[0] = 0;
            state[0] = 1;
        }
        for(int i = 1; i < n; i++){
            if(game[i] == 1 && !state[i-1]){
                game[i] = 0;
                state[i] = 1;
                picked = true;
            }
        }
        int num = 0;

        for(int x : game){
            if(x == 1) num++;
        }

        if(num % 2 == 0 && picked){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }


        // for(int x : game) cout << x << " ";
        // cout << endl;


    }








    return 0;
}