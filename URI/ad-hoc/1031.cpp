#include <iostream>
using namespace std;

int f(int n, int k){   
    if (n == 1) return 0;
    return (f(n - 1, k) + k) % n    ;
}


int main(){
    ios_base::sync_with_stdio(0);
    int n;
    while (true){
        cin >> n;
        if (!n) break;
        int pos = 11, m = 1, cont = 1;
        while (m != pos){
            m = f(n - 1, cont++);
        }
        cout << cont - 1 << endl;
    }
    return 0;
}
