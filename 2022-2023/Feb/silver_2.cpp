//g++ silver_2.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct grazing{
    long long x, y, t;
};

int main(){

    int g, n; cin >> g >> n;

    long long ans = 0;

    vector<grazing> farm(g);

    for(int i = 0; i < g; i++){
        cin >> farm[i].x >>farm[i].y >> farm[i].t;
    }

    sort(begin(farm), end(farm), [](grazing& a, grazing& b){
        return a.t < b.t;
    });

    for(int i = 0; i < n; i++){
        long long x, y, t; cin >> x >> y >> t;

        auto upper = upper_bound(begin(farm), end(farm), t, [](long long time, const grazing& g){return g.t >= time;});

        if(upper == farm.end()) {
            auto lower = upper - 1;
            auto l = *lower;
            long long d_l = (x-l.x)*(x-l.x) + (y-l.y)*(y-l.y);
            if((t - l.t)*(t - l.t) < d_l) {
                ans++;
            }
        } else if(upper != farm.begin()) {
            auto u = *upper;
            auto lower = upper - 1;
            auto l = *lower;
            long long d_u = (x-u.x)*(x-u.x) + (y-u.y)*(y-u.y);
            long long d_l = (x-l.x)*(x-l.x) + (y-l.y)*(y-l.y);
            if(d_u > (u.t - t)*(u.t - t) || (t - l.t)*(t - l.t) < d_l) {
                ans++;
            }
        } else {
            auto u = *upper;
            long long d_u = (x-u.x)*(x-u.x) + (y-u.y)*(y-u.y);
            if(d_u > (u.t - t)*(u.t - t)) {
                ans++;
            }
        }

        // cout << ans << endl;

    }

    cout << ans;


    return 0;
}