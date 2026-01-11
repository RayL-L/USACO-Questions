//g++ Question_2.cpp && ./a.out

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k, n;
    string s;
    cin >> t >> k;

    for(int i = 0; i < t; i++){
        cin >> n >> s;
        vector<int> ansv(3*n);
        int right = 3 * n - 1;
        if(n % 2 != 0){
            cout << -1 << "\n";
        }
    }
    
    // code
    return 0;
}