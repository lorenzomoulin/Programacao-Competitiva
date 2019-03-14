#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, cases = 1;
    cin >> t;
    while(t--){
        int a, b, c, maior,medio ,menor;
        cin >> a >> b >> c;
        maior = max (a, max(b, c));
        menor = min(a, min(b, c));
        if (maior!= a && menor !=a)
            cout << "Case " << cases << ": " << a << endl;
        else if (maior!= b && menor !=b)
            cout << "Case " << cases << ": " << b << endl;
        else if (maior!= c && menor !=c)
            cout << "Case " << cases << ": " << c << endl;
        cases++;
    }
    return 0;
}
