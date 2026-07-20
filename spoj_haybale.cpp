//g++ spoj_haybale.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> hay(n,0);
    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        hay[a]++;
        if(b < n) hay[b]--;
    }

    for(int i = 1; i < n; i++){
        hay[i] += hay[i-1];
    }
    sort(hay.begin(), hay.end());

    printf("%d", hay[n/2]);

    return 0;
}