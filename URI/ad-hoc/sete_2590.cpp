#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
 //   cin.sync_with_stdio(0); cin.tie(0);
   // cin.exceptions(cin.failbit);
    int t;
        scanf("%d", &t);
    int m[] = {1, 7, 9, 3};
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", m[(n % 4)]);// << '\n';
    }
    return 0;
}
