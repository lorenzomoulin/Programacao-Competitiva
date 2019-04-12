#include <bits/stdc++.h>
#define rep(i, a, b) for(int i= a; i <(b); ++i)
using namespace std;

int main(){
    int n, a, b, c, x, y , z, maximo = 0;
    cin >> n >> a >> b >> c;
    rep(x, 0, n + 1){
        rep(y, 0, n + 1){
            if ((n - a*x - b*y) % c == 0){
                z = (n - a*x - b*y) / c;
                if (a*x + b*y + c*z == n){
                    if ((x + y + z) > maximo)
                        maximo = x + y + z;
                }
            }
        }
    }
    cout << maximo << endl;
    return 0;
}
