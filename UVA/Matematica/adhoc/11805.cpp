#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    int c = 1;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;
        int r = (k+p)%n;
        if (r)  cout << "Case " << c << ": "<< r << endl;
        else    cout << "Case " << c << ": "<< n << endl;
        c++;
    }
    return 0;
}
