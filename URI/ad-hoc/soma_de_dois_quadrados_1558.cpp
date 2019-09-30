#include <bits/stdc++.h>

using namespace std;

vector<int> sq;
int table[10001];
void calc(){
    for(int i = 0; i*i < 10001; i++){
        sq.push_back(i*i);
        table[i*i] = 1;
    }
}

int main(){
    memset(table, 0, sizeof table);
    calc();
    int n;
        
    while (cin >> n){
        
        bool sim = false;
        for (int i = 0; i < sq.size() && sq[i] <= n; i++){
            if (table[n - sq[i]]){
                
                cout << "YES\n";
                sim = true;
                break;
            }
        }
        if (!sim)
            cout << "NO\n";
    }
    
    return 0;
}
