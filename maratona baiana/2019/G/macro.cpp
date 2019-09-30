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
    int v[61], c[3], a, a2, sum, i, j, n;
    memset (v, 0, sizeof (v));
    memset (c, 0, sizeof (c));
    for (i = 0; i < 6; i++)
    {
        scanf ("%d", &a);
        v[a] = 1;
    }
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &a);
        sum = 0;
        for (j = 0; j < a; j++)
        {
            scanf ("%d", &a2);
            sum += v[a2];
        }
        if (sum - 3 > 0) c[sum - 4]++;
    }
    printf ("%d %d %d\n", c[2], c[1], c[0]);
    return 0;
}
