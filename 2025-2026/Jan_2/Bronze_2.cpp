// //g++ Bronze_2.cpp && ./a.out

#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<vector<int>> moves;
int bestScore = 0, num = 0;
vector<int> arr;

void moo(int pos) {
    if (pos == n) {
        int score = 0;
        for (int i = 0; i < k; i++) {
            int x = arr[moves[i][0]];
            int y = arr[moves[i][1]];
            int z = arr[moves[i][2]];

            if (x == 1 && y == 0 && z == 0) score++;
        }

        if (score > bestScore) {
            bestScore = score;
            num = 1;
        } else if (score == bestScore) {
            num++;
        }
        return;
    }

    arr[pos] = 0;
    moo(pos + 1);

    arr[pos] = 1;
    moo(pos + 1);
}








int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;

    moves.resize(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> moves[i][0] >> moves[i][1] >> moves[i][2];
        moves[i][0]--;
        moves[i][1]--;
        moves[i][2]--;
    }

    arr.resize(n);
    moo(0);

    cout << bestScore << " " << num << endl;










    return 0;
}