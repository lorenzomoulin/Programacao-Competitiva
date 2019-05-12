#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!a && !b && !c && !d)
            break;
        if (a == c && b == d)
            cout << "0\n";
        else if (abs(a-c) == abs(b-d) || a == c || b == d)
            cout << "1\n";
        else
            cout << "2\n";
             
    }
    return 0;
}
