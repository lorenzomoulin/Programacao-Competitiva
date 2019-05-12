#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int p, q;
        cin >> p >> q;
        int b = q - p, a = q, c = -(p*q), delta = b*b - (4*a*c) ;
        if (delta < 0){
            cout << "Impossible.\n";
            continue;
        }
        int sdelta = (int)sqrt(delta);
        int x1 = sqrt((-b + sdelta)/(2*a) + q), x2 = sqrt((-b - sdelta)/(2*a) + q);
            cout << x1 << " " << x2 << endl;
        if (sdelta*sdelta != delta ){
            cout << "Impossible.\n";
            continue;
        }
        if((-b + sdelta) % (2*a) != 0 && (-b - sdelta) % (2*a) != 0 ){
            cout << "Impossible.\n";
            continue;
        }
        if((-b + sdelta) % (2*a) == 0){
            int x1sq = (-b + sdelta)/(2*a) + q;
            int x1 = sqrt((-b + sdelta)/(2*a) + q), x2 = sqrt((-b - sdelta)/(2*a) + q);
            cout << x1 << " " << x2 << endl;
        }
        
    }
    return 0;
}
