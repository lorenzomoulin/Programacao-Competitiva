#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        if (b == 0){
            cout << 1 << endl;
        }
        else{
            int an = a, bn = b, n = 1;
            while(1){
                int aux = an;
                an = an*a - b*bn;
                bn = aux*b + a*bn;
                n++;    
                if (an >= 1073741824){
                    cout << "TOO COMPLICATED\n";
                    break;
                    
                }
                if (!bn){
                    cout << n << endl;
                    break;
                }
                
            }
        }
    }
    return 0;
}
