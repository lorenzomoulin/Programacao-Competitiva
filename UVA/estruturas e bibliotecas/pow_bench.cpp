#include  <bits/stdc++.h>



using namespace std;

int ownpow(int b, int e){ return e == 0 ?  1 :  (e % 2 ? b*ownpow(b, e - 1) : ownpow(b, e / 2)*ownpow(b, e / 2)); }



int main(){
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 10; j++)
            printf("%d\n", ownpow(10, j));
}
