#include <bits/stdc++.h>
#define rep(i, a, b) for(int i= a; i <(b); ++i)
#define endl "\n"
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if (!n)
            break;
        int s = 0;
        int ant;
        cin >> ant;
        rep(i, 1, n){
            int a;
            cin >> a;
            if (a - ant > 10)
                s += 10;
            else {
                s += a - ant;
            }
            ant = a;
        }
        cout << s + 10 << endl;
    }
    return 0;
}
