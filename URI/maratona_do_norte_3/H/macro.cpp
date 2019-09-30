#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int lis(int arr[], int l, int r, bool rev) {
	multiset<int> s;
	multiset<int>::iterator it;
	if (!rev){
	    for(int i = l; i <= r; i++) {
		    s.insert(arr[i]);
		    //it = s.upper_bound(arr[i]); //non-decreasing
		    it = ++s.lower_bound(arr[i]); //strictly increasing
		    if (it != s.end()) s.erase(it);
	    }
	}
	else {
	    for(int i = r; i >= l; i--) {
		    s.insert(arr[i]);
		    //it = s.upper_bound(arr[i]); //non-decreasing
		    it = ++s.lower_bound(arr[i]); //strictly increasing
		    if (it != s.end()) s.erase(it);
	    }
	}
	return s.size();
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    rep (i, 0, n)   cin >> a[i];
    int res = 0;
    rep (i, 0, n){
        res = max(res, lis(a, 0, i, false) + lis(a, i, n - 1, true));
    }
    cout << res << '\n';
    return 0;
}
