#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        int sum = 0;
        for(int i = 1; i * i <= m; i++){
            if (m % i == 0){
                if (m / i != i)
                    sum += m/i + i;
                else
                    sum += i;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
