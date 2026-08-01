#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

int n;
int area = 0, cir = 0;
vector<vector<bool>> visited;
vector<vector<char>> grid;
const int dx[]{0, 1, 0, -1};
const int dy[]{1, 0, -1, 0};

void dfs(int x, int y, int a, int c){
    stack<pair<int, int>> st;
    st.push({x, y});

    while(!st.empty()){
        x = st.top().first;
        y = st.top().second;
        st.pop();
        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == '.'){
            c++;
            continue;
        }
        if(visited[x][y]) continue;
        a++;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            st.push({x + dx[i], y+dy[i]});
        }
    }
    if(a > area){
        area = a;
        cir = c;
    }else if(a == area) cir = min(cir, c);
}





int main(){
    freopen("perimeter.in", "r", stdin);freopen("perimeter.out", "w", stdout);
    cin >> n;
    grid.assign(n, vector<char>(n));
    visited.assign(n, vector<bool>(n, false));

    for(vector<char> &v: grid){
        for(char &x : v) cin >> x;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '#'){
                if(!visited[i][j]){
                    dfs(i,j,0,0);
                }
            }
        }
    }



    cout << area << " " << cir;




    return 0;
}