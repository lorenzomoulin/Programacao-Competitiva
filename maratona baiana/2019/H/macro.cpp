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
    unsigned long long a;
    scanf ("%llu", &a);
    if (a) printf ("%d\n", int (log (a)/log (2)) + 1);
    else printf ("0\n");
    return 0;
}
