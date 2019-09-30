#include <bits/stdc++.h>

using namespace std;

bool mat[1010][1010];

int main(){
    int n, m;
    memset(mat, 0, sizeof mat);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mat[a][b] = mat[b][a] = 1;
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        mat[a][b] ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
