#include <bits/stdc++.h>
using namespace std;

#define debug(args...) cerr << args
#define pb push_back
#define mp make_pair

#define MAX 1e8

typedef long long ll;
typedef unsigned long long llu;

typedef complex<double> point;

ll merge_sort(vector<ll> vec) {
    vector<ll> a;
    vector<ll> b;

    if (vec.size() == 1)
        return 0;

    for (ll i = 0; i < vec.size(); i++) {
        if (i < vec.size() / 2) {
            a.pb(vec[i]);
        } else {
            b.pb(vec[i]);
        }
    }

    ll sum = 0;
    sum += merge_sort(a);
    sum += merge_sort(b);
    a.pb(-1000000);
    b.pb(-1000000);

    ll it_a = 0;
    ll it_b = 0;

    for (ll i = 0; i < vec.size(); i++) {
        if (a[it_a] > b[it_b]) {
            vec[i] = a[it_a];
            it_a++;
        } else {
            vec[i] = b[it_b];
            sum += a.size() - it_a - 1;

            it_b++;
        }
    }

    return sum;
}

int main(int argc, char** argv) {
    ll N;
    cin >> N;

    vector<ll> a(N, 0);

    for (ll i = 0; i < N; i++) {
        ll m, n;
        cin >> m >> n;
        a[i] = m*m + n*n;
    }

    cout << merge_sort(a) << '\n';

    return 0;
}
