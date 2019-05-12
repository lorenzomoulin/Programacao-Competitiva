#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
        
    sort(a, a + n);
    for(int i = n - 1; i >= 0; i--){
        if (sum - a[i] > a[i]){
            cout << i + 1 << "\n";
            return 0;
        }
        sum -= a[i];
    }
    cout << "0\n";
    return 0;
}
