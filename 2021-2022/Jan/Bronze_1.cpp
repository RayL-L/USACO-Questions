//g++ Bronze_1.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<string> cows(3), guess(3);
    vector<int> freq(26, 0);
    vector<vector<bool>> isGreen(3, vector<bool>(3, false));
    
    for(int i = 0; i < 3; i++) cin >> cows[i];
    for(int i = 0; i < 3; i++) cin >> guess[i];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            freq[cows[i][j] - 'A']++;
        }
    }

    int green = 0, yellow = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(cows[i][j] == guess[i][j]){
                green++;
                freq[cows[i][j] - 'A']--;
                isGreen[i][j] = true;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(!isGreen[i][j]){
                if(freq[guess[i][j]-'A'] > 0){
                    yellow++;
                    freq[guess[i][j]-'A']--;
                }
            }
        }
    }

    cout << green << endl << yellow;







    return 0;
}