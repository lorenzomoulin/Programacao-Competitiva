#include <bits/stdc++.h>
using namespace std;
#define LSONE(x) (x & -x)

typedef long long ll;

int main(){
    ll x;
    cin >> x;
    ll res = 0;
    while (x    ){
        x -= LSONE(x);
        res++;
    }
    cout << res << "\n";
    return 0;
}
