#include <bits/stdc++.h>
using namespace std;
#define ispoweroftwo(n) ((n&(n-1)) == 0)

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    
    if (!n)
        cout << "N";
    else if (ispoweroftwo(n + 1))
        cout << "S";
    else
        cout << "N";
    cout << "\n";
    return 0;
}
