#include <iostream>
#define MAXN 10000
using namespace std;

int pd[MAXN];

void f(int n, int k){   
    pd[0] = 0;
    for (int i = 1; i < n; i++){
        pd[i] = (pd[i-1] + k) % (i+1);
    }
}

int main(){
    int nc;
    cin >> nc;
    int i = 1;
    while(nc--){
        int n, k;
        cin >> n >> k;
        f(n, k);        
        cout << "Case " << i++ << ": " << pd[n - 1] + 1 << endl;
    }
    return 0;
}
