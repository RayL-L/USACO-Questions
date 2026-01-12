//g++ Bronze_2.cpp && ./a.out

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cow(n);
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }

    auto it = find(cow.begin(), cow.end(), 0);

    while(it != cow.end()){
        auto first = find(cow.begin(), cow.end(), 0);
        auto second = find(cow.begin()+1, cow.end(), 0);
    }










    return 0;
}