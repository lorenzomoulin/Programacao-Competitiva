#include <iostream>
using namespace std;
typedef long long ll;
#define MAXN 10001
ll dp[MAXN];

int soma(ll k){
    int s = 0;
    while(k > 0){
        s += k % 10;
        k /= 10;
    }
    return s;
}

void calc(int k){
    dp[1] = 19;
    for (int i = 2; i <= k; i++){
        ll j = dp[i - 1] + 9;
        while (soma(j) != 10){
            j += 9;
        }
        dp[i] = j;
    }
}

int main(){
    int k; cin >> k;
    calc(k);
    cout << dp[k] << endl;
    return 0;
}
