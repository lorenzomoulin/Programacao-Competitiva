#include <iostream>
#include <cstring>
#include <string>
#define MOD 1500
using namespace std;

typedef long long ll;
int fib[1501];
char s[10010];

void calc(){
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 1500; i++) {fib[i] = (fib[i-1] % 1000 + fib[i-2] % 1000) % 1000; }
}

int mod_exp(int a, int b){
    if (b == 0) return 1;
    ll c = mod_exp(a, b / 2);
    c = (c * c) % MOD;
    if (b % 2)  c = (c * a) % MOD;
    return c;
}

int main(){
    int n;
    calc();
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        int num_mod = 0; int tam = strlen(s);int exp = 0;
        for (int i = tam - 1; i >= 0; i--){
            if(s[i] == '1')
                num_mod = (num_mod + (s[i] - '0') * mod_exp(2, exp)) % MOD;
                
            exp++;
        }
        printf("%03d\n", fib[num_mod]);
    }
    return 0;
}
