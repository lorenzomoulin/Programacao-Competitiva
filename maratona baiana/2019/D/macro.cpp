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
    pii d[3];
    int a, i;
    scanf ("%d %d %d", &(d[0].first), &(d[1].first), &(d[2].first));
    for (i = 0; i < 3; i++) d[i].second = i;
    sort (d, d+3);
    if (d[0].first > 12) printf ("invalida\n");
    else if (d[1].first > 30) printf ("invalida\n");
    else if (d[1].first <= 12) printf ("ambigua\n");
    else if (d[2].first <= 30) printf ("ambigua\n");
    else
    {
        char r[3];
        r[d[0].second] = 'm';
        r[d[1].second] = 'd';
        r[d[2].second] = 'a';
        printf ("%c-%c-%c\n", r[0], r[1], r[2]);
    }
    return 0;
}
