#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    while (true){
        int n; 
        cin >> n;
        if (!n)
            break;
        ll a[n];
        for (int i = 0 ; i < n ; i++)
            cin >> a[i];
        ll sum = 0;
        for(int i = n- 1; i >= 0; i--){
            sum += a[i];
            for (int j = i - 1; j >= 0; j--)
                a[j] += a[i];
        }
        cout << sum << '\n';
    }
    
    return 0;
}
