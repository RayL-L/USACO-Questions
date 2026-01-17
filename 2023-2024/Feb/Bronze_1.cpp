//g++ Bronze_1.cpp && ./a.out

#include <cassert>
#include <iostream>
using namespace std;

int main(){

int t;
cin >> t;

for(int i = 0; i < t; i++){
    string s;
    cin >> s;

    if(s[s.size()-1] == '0'){
        cout << "E\n";
    }else{
        cout << "B\n";
    }
    
}

    return 0;
}