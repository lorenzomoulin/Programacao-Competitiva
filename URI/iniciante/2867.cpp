#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int main() {
 
    int c, n, m;
    cin >> c;
    for (int i = 0; i < c; i++){
        cin >> n;
        cin >> m;
        int q = 1 + m*log10(n);
        printf("%d\n", q);
    }
    return 0;
}
