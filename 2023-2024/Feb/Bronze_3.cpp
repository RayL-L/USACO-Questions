//g++ Bronze_3.cpp && ./a.out

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_SIZE = 1000000;
    int n, q; cin >> n >> q;
    vector<int> c(n), t(n), visit(MAX_SIZE);
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    for(int i = 0; i < n; i++){
        int diff = c[i] - t[i] - 1;
        if(diff >= 0){
            visit[diff]++;
        }
    }

    for(int i = MAX_SIZE-2; i >= 0; i--){
        visit[i] += visit[i+1];
    }

    for(int i = 0; i < q; i++){
        int v, s;
        cin >> v >> s;
        if(visit[s] >= v){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    
















    // for(int Q = 0; Q < q; Q++){
    //     int v, s, numVisited = 0; cin >> v >> s;
    //     if(t.size() < v){
    //         cout << "NO\n";
    //         continue;
    //     }
    //     bool adv = false;
    //     vector<int> visitTime(n);

    //     for(int i = 0; i < n; i++){
    //         visitTime[i] = t[i] + s;
    //         if(visitTime[i] < c[i]) numVisited++;
    //         if(numVisited >= v){
    //             cout << "YES\n";
    //             adv = true;
    //             break;
    //         }
    //     }
        
    //     if(!adv) cout << "NO\n";
        
    // }
}