#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
using graph = vector<vi>;
const int MAXN = 2e5+9;
vi parent, depth, heavy, head, pos;
int cur_pos;
vector<pair<int, pii>> q1, q2;

int dfs(int v, graph const&adj){
    int size = 1;
    int max_c_size = 0;
    
    for(int c: adj[v]){
        if (c != parent[v]){
            parent[c] = v; depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h, graph const&adj){
    head[v] = h, pos[v] = cur_pos++;
    if(heavy[v] != -1)
        decompose(heavy[v], h, adj);
    trav(c, adj[v]){
        if (c != parent[v] && c != heavy[v])
            decompose(c,c,adj);
    }
}

void init(graph const&adj){
    int n = sz(adj);
    //cout << n << endl;
    parent = vi(n);
    depth = vi(n);
    heavy = vi(n, -1);
    head = vi(n);
    pos = vi(n);
    cur_pos = 0;
    //cout << "legal" << endl;
    dfs(0, adj);
    //cout << "dfs passou " << endl;
    decompose(0, 0, adj);
}

void query(int a, int b, int c){
    
    for(; head[a] != head[b]; b = parent[head[b]]){
        if (depth[head[a]] > depth[head[b]])
            swap(a,b);
        int l = min(pos[head[b]], pos[b]), r = max(pos[head[b]], pos[b]);
        if (c == 1)
            q1.push_back(piii(head[b], pii(l,r)));
        else
            q2.push_back(piii(head[b], pii(l,r)));
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int l = min(pos[a],pos[b]), r = max(pos[a],pos[b]);
    
    if (c == 1)
        q1.push_back(piii(head[a], pii(l, r)));
    else
        q2.push_back(piii(head[a], pii(l, r)));
    sort(all(q1));
    sort(all(q2));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    graph g(n);
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //cout << "oi" << endl;
    init(g);
    //cout << "init passou " << endl;
    rep(k, 0, q){
        int a,b,c,d;
        cin >> a >> b>> c>> d;
        a--, b--, c--, d--;
        q1.clear(); q2.clear();
        query(a,b,1);
        query(c,d,2);
        
        int i = 0, j = 0, cnt = 0;
        while(i < sz(q1) && j < sz(q2)){
            if (q1[i].first < q2[j].first) i++;
            else if (q2[j].first < q1[i].first) j++;
            else{
                if (max(q2[j].second.first, q1[i].second.first) > min(q2[j].second.second, q1[i].second.second)){
                    i++, j++;
                }
                else{
                    cnt +=  min(q2[j].second.second, q1[i].second.second) - max(q2[j].second.first, q1[i].second.first)  +1;
                    i++, j++;
                }
                
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
