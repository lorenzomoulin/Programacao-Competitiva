#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 10009
#define WHITE 0
#define GRAY 1
#define BLACK 2
bool loop;
int n, m, vis[MAXN];

vi adjList[MAXN];
deque<int> ans;
void dfs(int v){
    vis[v] = GRAY;
    
    trav(a, adjList[v]){
        if (vis[a] == WHITE)
            dfs(a);
        else if (vis[a] == GRAY)
            loop = true;
    }
    vis[v] = BLACK;
    ans.push_front(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--){
        memset(vis, 0, sizeof vis);
        ans.clear();
        rep(i, 0, MAXN)
            adjList[i].clear();
        cin >> n >> m;
        rep(i, 0, m){
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
        }
        loop = false;
        rep(i,1 , n + 1)
            if (!vis[i])
                dfs(i);
        trav(a, ans)
            cout << a << ' ';
        cout << '\n';
        if (loop)
            cout << "SIM\n";
        else
            cout << "NAO\n";
        
    }
    return 0;
}
