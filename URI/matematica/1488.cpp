#include <iostream>

using namespace std;

int main(){
    int instancia = 0;
    
    while (true){
        
        long long n, m, p1, p2, p3, p4;
        cin >> n;
        if (!n) break;
        //if (instancia) cout << endl << endl;
        instancia++;
        //cout << endl;
        long long mf = 0;
        for (m = 1; m < n; m++){
            if ((n-2*m-1-m*m)%(m*m + 2*m + 1) == 0){
                p1 = m*(n-2*m-1-m*m)/(m*m + 2*m + 1);
                p2 = p1 + 2*m;
                p3 = (p1 + m)/m;
                p4 = m*p1 + m*m;
                mf = m;
            }
        }
        if (mf)
            cout << "Instancia " << instancia << endl << mf << " " << p1  << " " << p2 <<  " " <<  p3  << " " 	<< p4 << endl << endl;
        else cout << "Instancia " << instancia << endl << n << " nao e quadripartido" << endl << endl;
    }
    return 0;
}
