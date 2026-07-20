//g++ silver_2.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;

    ll ans = 0;

    vector<int> x(n),y(n);

    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<int> col(n), row(n), idx(n);
    for(int i = 0; i < n; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), [&](int a, int b){return x[a] < x[b];});
    for(int i = 0; i < n; i++) row[idx[i]] = i+1;

    sort(idx.begin(), idx.end(), [&](int a, int b){return y[a] < y[b];});
    for(int i = 0; i < n; i++) col[idx[i]] = i+1;


    vector<vector<int>> pre(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++){
        pre[row[i]][col[i]] = 1;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int l = min(col[i], col[j]);
            int r = max(col[i], col[j]);
            int top = min(row[i], row[j]);
            int bottom = max(row[i],row[j]);

            int above = pre[top][r] - pre[top][l-1];
            int below = pre[n][r] - pre[bottom-1][r] - pre[n][l-1] + pre[bottom-1][l-1];
            ans += above * below;
        }
    }

    cout << ans + 1 + n;









    return 0;
}