#include <bits/stdc++.h>

using namespace std;

int ackermann(int m, int n){
    if (m == 0)
        return n+1;
    if (m > 0 && n == 0)
        return ackermann(m-1, 1);
    if (m > 0 && n > 0 )
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main(){
    cout << ackermann(3, 6) << endl;
    return 0;
}
