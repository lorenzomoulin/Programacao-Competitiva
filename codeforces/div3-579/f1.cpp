#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool cmp(pii a, pii b){
    return a.first + a.second > b.first + b.second;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, r;
    cin >> n >> r;
    pii win[n], lose[n];
    int w = 0, l = 0;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        if (b >= 0)
            win[w++] = pii(a, b);
        else
            lose[l++] = pii(a, b);
    }/*
    rep (i, 0, w)
        cout << win[i].first << " " << win[i].second << ' ';
    cout << '\n';
    rep(i, 0, l)
        cout << lose[i].first << ' ' << lose[i].second << ' ';
    cout << '\n'; */
    sort(win, win + w);
    sort(lose, lose + l, cmp);
    rep (i, 0, w){
        if (r < win[i].first){
            cout << "NO\n";
            return 0;
        }
        r += win[i].second;
    }
    rep(i, 0, l){
        if (r < lose[i].first){
            cout << "NO\n";
            return 0;
        }
        r += lose[i].second;
    }
    cout << (r >= 0 ? "YES" : "NO" ) << '\n';
    return 0;
}
