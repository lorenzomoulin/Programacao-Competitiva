#include <iostream>
#include <cstring>

#define N 1500

typedef unsigned long long ull;

using namespace std;

ull f[N+1];

int mod(string num){
    int res = 0;
    for (int i = 0; i < num.length(); i++){
        res = (res*10 + (int)num[i] - '0') % N;
    }
    return res;
}

void calc(){
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= N; i++)
        f[i] = (f[i-1] + f[i-2]) % 1000;
}

int tresUlt(string a){   return f[mod(a)];}

int main(){
    int t;
    cin >> t;
    calc();
    while(t--){
        string a;
        cin >> a;
        printf("%.3d\n", tresUlt(a));
    }
    return 0;
}
