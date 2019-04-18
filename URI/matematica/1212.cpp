#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int main(){
    while (true){
        string a, b;
        cin >> a >> b;
        if (!a.compare("0") && !b.compare("0"))
            break;
        int carry = 0, cont = 0;
        
        if ((int)a.size() < (int)b.size()){
            string temp;
            for (int i = 0; i < (sz(b) - sz(a)); ++i)
                temp += '0';
            a = temp + a;
        }
        else if ((int)b.size() < (int)a.size()){
            string temp;
            for (int i = 0; i < (sz(a) - sz(b)); ++i)
                temp += '0';
            b = temp + b;
        }
        
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j){
            int res = (a[i] - '0') + (b[j] - '0') + carry;
            if (res >= 10)
                carry = 1;
            else
                carry = 0;
            if (carry)
                cont++;
        }
        if (!cont)
            cout << "No carry operation.\n";
        else{
            cout << cont << " carry operation";
            cont == 1? cout << ".\n":cout << "s.\n";
        }
    }
    return 0;
}
