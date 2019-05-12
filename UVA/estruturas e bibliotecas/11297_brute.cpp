#include <bits/stdc++.h>
#define rep(i, a, b) for(int i= a; i < (b); ++i)
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin >> n;
    int tree[n + 1][n + 1];
    rep(i, 1, n + 1)
        rep(j, 1, n + 1)
            cin >> tree[i][j];
    int q;
    cin >> q;
    while(q--){
        char ch;
        int a, b, c, d;
        cin >> ch;
        if (ch == 'c'){
            cin >> a >> b >> c;
            
            tree[a][b] = c;
        }
        else {
            cin >> a >> b >> c >> d;
            int big = INT_MIN, small = INF;
            rep(i, a, c + 1){
                rep(j, b, d + 1){
                    tree[i][j] > big ? big = tree[i][j]:big;
                    tree[i][j] < small ? small = tree[i][j]:small;
                }
            }
            cout << big << " " << small << endl;
        }
        
    }
    return 0;
}
