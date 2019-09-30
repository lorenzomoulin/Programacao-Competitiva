#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int neutral = 0;
#define comp(a, b) ((a)+(b))
#define MAXN 2010


int n, k, grid[MAXN][MAXN], wr[MAXN], gridcol[MAXN][MAXN], gridrow[MAXN][MAXN], wc[MAXN];
pii row[MAXN], col[MAXN];
char mat[MAXN][MAXN];

int checkrow(int i, int j){
    return row[i].first >= j && (row[i].second <= j + k - 1) && !wr[i];
}

int checkcol(int i, int j){
    return col[j].first >= i && (col[j].second <= i + k - 1) && !wc[j];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    int wl = 0;
    rep (i, 0, n){
        int l = -1, r = -1;
        rep(j, 0, n){
            cin >> mat[i][j];
            if (mat[i][j] == 'B' && l < 0)
                l = j;
            if (l >= 0 && mat[i][j] == 'B')
                r = j;
        }
        wl += (l < 0 && r < 0);
        wr[i] = (l < 0 && r < 0);
        row[i] = pii(l, r);
    }
    
    rep(j, 0, n){
        int l = -1, r = -1;
        rep(i, 0, n){
            if (mat[i][j] == 'B' && l < 0)
                l = i;
            if (l >= 0 && mat[i][j] == 'B')
                r = i; 
        }
        wl += (l < 0 && r < 0);
        wc[j] = (l < 0 && r < 0);
        col[j] = pii(l, r);
    }
    
    rep(i, 0, n - k + 1){
        if (i == 0){
            rep(j, 0, k){
                rep(h, 0, n - k + 1){
                    if (checkrow(j, h))
                        gridrow[i][h]++;
                }
            }
        }
        else {
            rep(j, 0, n - k + 1){               
                    gridrow[i][j] = gridrow[i - 1][j] - checkrow(i-1,j);
                    gridrow[i][j] += checkrow(i + k - 1, j);
            }
        }
    }
    rep(j, 0, n - k + 1){
        if (j == 0){
            rep(h, 0, n - k + 1){
                rep(i, 0, k){
                    if (checkcol(h, i))
                        gridcol[h][j]++;
                }
            }
        }
        else {
            rep(i, 0, n - k + 1){
                    gridcol[i][j] = gridcol[i][j-1] -checkcol(i, j -1);
                    gridcol[i][j] += checkcol(i, j + k - 1);
            }
        }
    }
    int res = 0;
    rep(i, 0, n - k + 1){
        rep (j, 0, n - k + 1)
            grid[i][j] += gridrow[i][j] + gridcol[i][j], res = max(res, grid[i][j]);
    }
    cout << wl + res << '\n';
    return 0;
}
