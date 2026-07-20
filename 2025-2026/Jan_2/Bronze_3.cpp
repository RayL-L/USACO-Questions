// g++ Bronze_3.cpp && ./a.out

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n; i++) a[i] = min(a[i], 2 * a[i - 1]);

    int mx = min(n, 60);

    vector<ll> num(mx + 1);
    num[1] = 1;
    for (int i = 2; i <= mx; i++) num[i] = num[i - 1] * 2;

    while (Q--) {
        ll m;
        cin >> m;

        ll cost = 0;
        ll ans = LLONG_MAX;

        for (int i = mx; i >= 1; i--) {
            ll cnt = m / num[i];
            cost += cnt * a[i];
            m -= cnt * num[i];

            ans = min(ans, cost + (m > 0 ? a[i] : 0));
        }

        cout << ans << '\n';
    }

    return 0;
}