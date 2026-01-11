//g++ Question_1.cpp && ./a.out

#include <iostream>
using namespace std;

long long answer(long long a, long long b, long long ca, long long cb, long long fa){

    if(a >= fa){
        return 0;
    }else{
        long long A = b/cb * ca + a;
        long long B = b - b/cb * cb;
        if(A >= fa){
            return 0;
        }else{
            long long da = fa - A;
            long long r;

            if(da % ca == 0){
                r = da/ca;
            }else{
                r = da/ca + 1;
            }

            long long ans = 1LL * r * cb - B;

            bool check = (ans + b - 1)/cb * ca + a + 1 >= fa;


            if(check){
                return ans;
            }else{
                return ans + 1;
            }

            // ans = ans + (ca-1 + (fa - (ans+b)/cb *ca - a));
            // return ans;

            

        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long a, b, ca, cb, fa;
        cin >> a >> b >> ca >> cb >> fa;

        long long ans = answer(a, b, ca, cb, fa);

        cout << ans << "\n";


    }
    
    // code
    return 0;
}