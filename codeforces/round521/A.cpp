#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    while (n--){
        ll a, b, k;
        cin >> a >> b >> k;
        k % 2?cout << ((k+1)/2)*a - k/2*b << endl: cout << k/2*a - k/2*b << endl;
    }    
    return 0;
}
