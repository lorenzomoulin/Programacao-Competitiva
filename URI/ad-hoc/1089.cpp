#include <iostream>
#define lp(n, i) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    while(true){
        int n; cin >> n;
        if (!n) break;
        int h[n + 2];
        lp(n, i){
            cin >> h[i];
          //  cout << h[i] << " ";
             
        }
        h[n] = h[0];
        h[n + 1] = h[1];
        //cout << endl;
        bool cres = h[1] > h[0]?true:false;
        //cout << "crescendo = " << cres << endl;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            
            if (cres && h[i + 1] < h[i]){sum++; cres = false;}
            else if (!cres && h[i + 1] > h[i]){sum++; cres = true;}
            
            //cout << "crescendo = " << cres << endl << "picos = " << sum << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
