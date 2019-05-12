#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if (!n)
            break;
        int pos = 0;
        while (n--){
            char a;
            cin >> a;
            if (a == 'D')
                pos++;
            else
                pos--;
            if (pos < 0)
                pos += 4;
            pos %= 4;
        }
        if (pos == 0)
            cout << "N\n";
        else if (pos == 1)
            cout << "L\n";
        else if (pos == 2)
            cout << "S\n";
        else 
            cout << "O\n";
       
    }
    return 0;
}
