#include <bits/stdc++.h>
#define rep(i, a , b) for(int i = a; i <(b); ++i)
using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if(!n)
            break;
        int c[n];
        float eq = 0;
        rep(i, 0, n){
            float a;
            cin >> a;
            c[i] = a*100;
            eq += c[i];
        }
        eq /= n;
        //cout << eq =;<< endl;
        float change1 = 0, change2 =0;
        rep(i, 0, n){
            if (c[i] > eq)
                change1 += c[i] - eq;
            if (c[i] < eq)
                change2 += eq - c[i];
        }
        printf("$%.2f\n", min(change1, change2));
    }
    return 0;
}
