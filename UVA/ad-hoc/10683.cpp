#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll h, m, s, c;
    while(scanf("%02lld%02lld%02lld%02lld", &h,&m,&s,&c) != EOF){
        ll sum = 0;
        sum += h*60*60*100 + m*60*100 + s*100 + c;
        sum *= 1000;
        sum /= 864;
        printf("%07lld\n", sum);
    }
    return 0;
}
