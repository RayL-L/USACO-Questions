//g++ silver_2.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<vector<int>> wall(1001, vector<int>(1001, 0));

    int row = 0, col = 0;

    for(int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        row = max(row, c);
        col = max(col, d);

        wall[a][b]++;
        wall[a][d]--;
        wall[c][b]--;
        wall[c][d]++;
    }

    int ans = 0;

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){

            if(r > 0) wall[r][c] += wall[r-1][c];
            if(c > 0) wall[r][c] += wall[r][c-1];
            if(r > 0 && c > 0) wall[r][c] -= wall[r-1][c-1];

            if(wall[r][c] == k) ans++;
        }
    }

    cout << ans;

    return 0;
}