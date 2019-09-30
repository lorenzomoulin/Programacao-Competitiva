#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXD 11

struct box{
    vi arr;
    int id;
public:
    bool operator < (box a) const{
        rep(i, 0, sz(arr)){
            if (arr[i] >= a.arr[i])
                return false;
        }
        return true;
    }      
 
};


bool cmp(box a, box b){
    rep(i, 0, sz(a.arr)){
        if (a.arr[i] == b.arr[i])
            continue;
        else return a.arr[i] < b.arr[i];
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int k, n;
    while ( cin >> k >> n){
        box arr[k];
        rep(i, 0, k){
            arr[i].id = i + 1;
            rep(j, 0, n){
                int a;
                cin >> a;
                arr[i].arr.push_back(a);  
            }
            sort(all(arr[i].arr));    
        }
        sort(arr, arr + k, cmp);
        int dp[k], parent[k];
        rep(i, 0, k) dp[i] = 1, parent[i] = i;
        rep(i, 1, k)rep(j, 0, i){
            if (arr[j] < arr[i]){
                if (dp[i] < dp[j] + 1)
                    parent[i] = j;    
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        cout << *max_element(dp, dp + k) << '\n';
        deque<int> res;
        int a = max_element(dp, dp + k) - dp;

        while (parent[a] != a){
            res.push_front(a);
            a = parent[a];
        }
        res.push_front(a);
        cout << arr[res[0]].id;
        res.pop_front();
        trav(x, res)
            cout << ' '<< arr[x].id;
        cout << '\n';
    }
    
    return 0;
}
