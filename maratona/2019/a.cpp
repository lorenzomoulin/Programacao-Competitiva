#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define SQ(x) (x)*(x)
#define ESQ 0
#define DIR 1
#define CIMA 2
#define BAIXO 3

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5+9;
int m, n, k, visited[MAXN];
pair<pii, int> s[MAXN];
vi graph[MAXN];

void dfs(int u){
    visited[u] = 1;
    trav(a, graph[u]){
        if (!visited[a])
            dfs(a);
    }
}

void add_edge(int i, int j){
    graph[i].push_back(j);
    graph[j].push_back(i);
}

bool intersect(int i, int j){
    return SQ(s[i].second + s[j].second) >= (SQ(s[i].first.first - s[j].first.first) + SQ(s[i].first.second - s[j].first.second));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> m >> n >> k;
    memset(visited, 0, sizeof visited);
    rep(i,4 , k + 4) {
        int x, y, si;
        cin >> x >> y >> si;
        s[i] = pair<pii, int>(pii(x, y), si); 
        if (x - si <= 0)    add_edge(i, ESQ);
        if (x + si >= m)    add_edge(i, DIR);
        if (y + si >= n)    add_edge(i, BAIXO);
        if (y - si <= 0)    add_edge(i, CIMA);
    }
    rep(i, 4, k + 4){
        rep(j, i + 1, k + 4){
            if (intersect(i, j))    add_edge(i, j);
        }
    }
    
    dfs(ESQ);
    if (visited[DIR] || visited[CIMA]){
        cout << "N\n";
        return 0;
    }
    memset(visited, 0, sizeof visited);
    dfs(BAIXO);
    if (visited[CIMA] || visited[DIR])
        cout << "N\n";
    else
        cout << "S\n";
    return 0;
}
