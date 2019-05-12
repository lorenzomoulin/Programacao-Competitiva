#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, caso = 1;
    cin >> n;
    while (n--){
        int m[9][9];
        bool err = false;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> m[i][j];
        for (int i = 0; i < 9; i++){
            set<int> s;
            for (int j = 0; j < 9; j++)
                s.insert(m[i][j]);
            if (s.size() < 9){
                err = true;
                break;
            }
            if (err)
                break;
        }
        for (int j = 0; j < 9; j++){
            set<int> s;
            for (int i = 0; i < 9; i++)
                s.insert(m[i][j]);
            if (s.size() < 9){
                err = true;
                break;
            }
            if (err)
                break;
        }

        for (int k = 0; k < 3; k++){
            for (int l = 0; l < 3; l++){
                
                set<int>s;
                int ifinal = (k % 3)*3 + 3, jfinal = (l % 3)*3 + 3;
                for (int i = (k % 3)*3; i < ifinal; i++){
                    for (int j = (l % 3)*3; j < jfinal; j++)
                    s.insert(m[i][j]);
                }
                if (s.size() < 9){
                    err = true;
                    break;
                }
            }
            if (err)
                break;
        }
        
        cout << "Instancia " << caso << "\n" << (err ? "NAO" : "SIM") << "\n\n";
        
        caso++;     
    }
    return 0;
}
