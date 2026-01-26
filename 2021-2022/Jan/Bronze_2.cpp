//g++ Bronze_1.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;

bool beat(vector<int>& DA, vector<int>& DB){
    int w = 0, l = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(DA[i] > DB[j]) w++;
            if(DA[i] < DB[j]) l++;
        }
    }
    return w > l;
}

void solve(){
    vector<int> DA(4), DB(4), DC(4);
    for(int i = 0; i < 4; i++) cin >> DA[i];
    for(int i = 0; i < 4; i++) cin >> DB[i];
    bool awin;

    if(beat(DA, DB)){
        awin = true;
    }else if(beat(DB, DA)){
        awin = false;
    }else{
        cout << "no" << endl;
        return;
    }

    
    for(DC[0] = 1; DC[0] <= 10; DC[0]++){
        for(DC[1] = DC[0]; DC[1] <= 10; DC[1]++){
            for(DC[2] = DC[1]; DC[2] <= 10; DC[2]++){
                for(DC[3] = DC[2]; DC[3] <= 10; DC[3]++){
                    if(awin){
                        if(beat(DC, DA) && beat(DB, DC)){
                            cout << "yes" << endl;
                            return;
                        }
                    }else{
                        if(beat(DC, DB) && beat(DA, DC)){
                            cout << "yes" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "no" << endl;

}

int main(){

    int t = 0; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }














    return 0;
}