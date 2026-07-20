// g++ silver_3.cpp && ./a.out

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");

    int n, q;
    cin >> n >> q;

    vector<int> one(n + 1, 0), two(n + 1, 0), three(n + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            one[i] = one[i - 1] + 1;
            two[i] = two[i - 1];
            three[i] = three[i - 1];
        } else if (a == 2) {
            one[i] = one[i - 1];
            two[i] = two[i - 1] + 1;
            three[i] = three[i - 1];
        } else {
            one[i] = one[i - 1];
            two[i] = two[i - 1];
            three[i] = three[i - 1] + 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        cout << one[b] - one[a] << " "
        << two[b] - two[a] << " "
        << three[b] - three[a] << endl;
    }

    // for(int i = 0; i < n+1; i++){
    //     cout << one[i];
    // }

    return 0;
}