#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, float> sf;
        for (int i = 0; i < n; i++){
            string a;
            float preco;
            
            cin >> a >> preco;
            sf.insert(pair<string, float>(a, preco));
        }
        int m;
        float res = 0;
        cin >> m;
        for (int i = 0; i < m; i++){
            string a;
            int qtd;
            cin >> a >> qtd;
            res += qtd*sf[a];
        }
        printf("R$ %.2f\n", res);
    }
    return 0;
}
