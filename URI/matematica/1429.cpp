#include <cmath>
#include <iostream>

using namespace std;

int fact[10] = {1,1,2,6,24,120,720,5040, 40320, 362880};

int main(){

    while (true){
        int n;
        cin >> n;
        if (!n) break;
        
        int acm = 0;
        for (int i = 1; n > 0; i++){
            acm += (n%10)*fact[i];
            n/=10;
        }
        cout << acm << endl;
    }
    return 0;
}
