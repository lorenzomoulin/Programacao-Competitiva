#include <bits/stdc++.h>

using namespace std;

int max_sum(int *a, int n){
    int maior = 0, resp1 = 0;
    for (int i = 0; i < n; i++){
        maior = max(0, maior + a[i]);
        resp1 = max(resp1, maior);
    }
    int soma = 0;
    for (int i = 0; i < n; i++){
        soma += a[i];
        a[i] = -a[i];
    }
    int resp2 = 0;
    maior = 0;
    for (int i = 0; i < n; i++){
        maior = max(0, maior + a[i]);
        resp2 = max(resp2, maior);
    }
    
    return max(resp1, soma + resp2);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        
    }
    
    cout << max_sum(a, n) << '\n';
    return 0;
}
