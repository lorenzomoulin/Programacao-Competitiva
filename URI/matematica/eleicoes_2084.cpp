#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], sum = 0, big = 0, idx;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if (a[i] > big){
            big = a[i];
            idx = i;
        }
    }
    double f = 0.45*sum, s = 0.4*sum;
    
    if (big - f >= 0 )
        cout << "1\n";
    else if (big - s >= 0){
        
        for (int i = 0; i < n; i++){
            
            if (i != idx){
                if ((big - a[i])*1.0/sum - 0.1*sum < EPS){
                    cout << "2\n";
                    return 0;
                }
            }
        }
        cout << "1\n";
    }
    else
        cout << "2\n";
    return 0;
}
