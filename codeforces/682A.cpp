#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    int c = m / 5;
    ll cont = 0;
    for (int i = 1; i <= n; i++){
        int m0 = 5 - i % 5;
        if (m0 + 5*c > m)    cont += c;
        else cont += c + 1;
    }
    cout << cont << endl;
    return 0;
}
