#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void divi(ll k, ll n){
    vector<ll> a;
    for (ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (n / i == i){
                a.push_back(i);
            }
            else{
                a.push_back(n / i);
                a.push_back(i);
            }
        }
    }
    sort(a.begin(), a.end());
    if (a.size() < k)  cout << -1 << endl;
    else
        cout << a[k - 1] << endl;
}

int main(){
    ll n, k; cin >> n >> k;
    divi(k, n);
    return 0;
}
