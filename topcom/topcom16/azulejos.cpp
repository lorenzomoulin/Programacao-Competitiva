#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fat(ll n){
    return (n < 2LL ? 1LL : n*fat(n - 1));
}

ll res[] = {1, 1, 2, 7, 18, 60, 196, 704, 2500, 9189, 33896, 126759, 476270, 1802312, 6849777, 26152418, 100203194, 385221143, 1485200848, 5741256764, 22245940545, 86383382827, 336093325058, 1309998125640, 5114451441106, 19998172734786, 78306011677182, 307022182222506, 1205243866707468, 4736694001644862}; 

int main(){
    ll n;
    cin >> n;
    cout << res[n - 1] << "\n";
    return 0;
}
