#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define INF 0x3f3f3f3f

int res[38][38], mf, f, s = 0, t = 37, total = 0;
vi p;

void augment(int v, int minEdge){
    if (v == s){    f = minEdge; return ;}
    else if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
    string str;
    memset(res, 0, sizeof res);
    while (getline(cin, str)){
        //cout << str << '\n';
        if (!str.compare("")){
            scanf("\n");
            rep(i, 27, 37){
                res[i][t] = 1;
            }
            
            //calc fluxo
            mf = 0;
            while (1){
                f = 0;
                vi dist(38, INF); dist[s] = 0; queue<int> q; q.push(s);
                p.assign(38, -1);
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    if (u == t) break;
                    rep(v, 0, 38){
                        if (res[u][v] > 0 && dist[v] == INF)
                            dist[v] = dist[u] + 1, q.push(v), p[v] = u; 
                    }
                }
                augment(t, INF);
                if (f == 0) break;
                mf += f;
            }
            if (mf == total){
                rep(c, 27, 37){
                    bool tem = false;
                    rep(a, 1, 27){
                        if (res[c][a]){
                            tem = true, printf("%c", 'A' + a - 1);
                            break;
                        }
                    }
                    if (!tem)
                        printf("_");
                }
                cout << '\n';
            }
                //cout << "OK\n";
            else
                cout << "!\n";
            memset(res, 0, sizeof res);
            total = 0;
            
        } else {
            int app = str[0] - 'A' + 1, w = str[1] - '0';
            total += w;
            res[s][app] = w;
            rep(i, 3, sz(str) - 1){
                res[app][27 + str[i] - '0'] = INF;
            }
        }
    }

    return 0;
}
