//g++ Bronze_2.cpp && ./a.out

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int> nums(n), goal(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n; i++) cin >> goal[i];

    int ans = 0;

    for(int i = 0; i < n; i++){
        int index = find(goal.begin(), goal.end(), nums[i]) - goal.begin();
        if(index > i) ans++;
    }

        
    if(ans == 0) cout << 0;
    else cout << n - ans;
    return 0;
}