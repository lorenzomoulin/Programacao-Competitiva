#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll acum[1000001];

void calc(){
    acum[1] = 1;
    for (int i = 2; i <= 1000000; i++){
        ll sum = 0;
        for(int j = 1; j * j <= i; j++){
            if (i % j == 0){
                if (i / j != j)
                    sum += i/j + j;
                else
                    sum += j;
            }
        }
        acum[i] = acum[i -1] + sum;
    }
}

int main(){
    calc();
    while (true){
        int n;
        scanf("%d", &n);
        if (!n) break;
        printf("%lld\n", acum[n]);
    }
    return 0;
}
