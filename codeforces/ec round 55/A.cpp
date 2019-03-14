#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int cont1 = 0, cont2 = 0;
        
        if ((y - x) % d == 0 || (x - y) % d == 0){
            x < y? cout << (y - x) / d: cout << (x - y) / d;
            cout  << endl;
            continue;
        }
        
        if ((y - 1) % d == 0){
            cont1 = ceil((x - 1) / (float)d) + (y - 1) / d;
            //cout << "thau\n";
        }
        
        if ((n - y) % d == 0){
            cont2 = ceil((n - x) /(float) d) + (n - y) / d;
        }
        
        if (!cont1 && !cont2){
            cout << "-1\n";
            continue;
        }
        
        if (!cont1){
            //cout << "fim\n";
            cout << cont2 << endl;
            continue;
        }
        
        if (!cont2){
            //cout << "inicio\n";
            cout << cont1 << endl;
            continue;
        }
        //cout << "oi\n"; 
        cout << min (cont1, cont2) << endl;
    }
    
    
    return 0;
}
