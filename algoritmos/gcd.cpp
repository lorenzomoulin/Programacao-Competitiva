#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    gcd(b, a%b);
}

int gcd_n(int* an, int n){
    if (n == 2) return gcd(an[0], an[1]);
    
    gcd(gcd_n(an, n-1), an[n-1]);
}

int main (){
/*
    int a,b;
    cin >> a >> b;
    printf("%d\n", gcd(a, b));*/
    int n, N;
    cin >> n;
    N = n;
    int an[N];
    int i = 0;
    while (n--){
        int num;
        cin >> num;
        an[i++] = num;
    }
    cout << gcd_n(an, N) << endl;

}
