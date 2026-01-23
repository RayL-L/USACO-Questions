//g++ Bronze_1.cpp && ./a.out

#include <iostream>
using namespace std;

int main(){
    int n, ans = 0, j=0, k;
    string cow;
    cin >> n >> cow;

    for(int i = 0; i < n; i++){
        int g = 0, h = 0;
        for(int j = i; j < n; j++){
            if(cow[j] == 'G') g++;
            else h++;

            if(h+g >= 3 && (g==1 || h==1)) ans++;
        }
    }

    cout << ans;








    return 0;
}