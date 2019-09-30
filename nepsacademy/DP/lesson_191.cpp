#include <bits/stdc++.h>

using namespace std;

int max_sum(int *a, int n){
    int maior = 0, resp = 0;
    for(int i = 0; i < n; i++){
        maior = max(0, maior + a[i]);
        resp = max(resp, maior);
    }
    return resp;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << max_sum(a, n) << '\n';
    return 0;
}
