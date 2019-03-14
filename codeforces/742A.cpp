#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    if (n == 0) {cout << 1 << endl; return 0;}
    int res[4] = {6, 8, 4, 2};
    cout << res[n % 4] << endl;
    return 0;
}
