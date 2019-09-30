#include <bits/stdc++.h>

using namespace std;

int mat[5][5], vis[5][5];

void flood (int i, int j){
    if (i < 0 || i > 4 || j < 0 || j > 4)   return ;
    if (vis[i][j])  return ;
    
    if (mat[i][j])  return ;
    vis[i][j] = 1;
    flood (i , j + 1);
    flood(i, j - 1);
    flood(i + 1, j);
    flood (i - 1, j);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        memset(mat, 0, sizeof mat);
        memset(vis, 0, sizeof vis);
        for (int i =0 ; i < 5; i++)
            for (int j = 0; j < 5; j++)
                cin >> mat[i][j];
        flood(0, 0);
        
        if (vis[4][4] )
            cout << "COPS\n";
        else 
            cout << "ROBBERS\n";
    }
    return 0;
}
