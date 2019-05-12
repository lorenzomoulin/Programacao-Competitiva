#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    while (cin >> a >> b >> c){
        if (a == b and b == c)
            cout << "*\n";
        else if (a != b and a != c)
            cout << "A\n";
        else if (b != a and b !=c)
            cout << "B\n";
        else
            cout << "C\n";
    }
    return 0;
}
