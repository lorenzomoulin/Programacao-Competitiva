#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        bitset<32> in, out;
        for(int i = 0; i < 32; i++){
            in[i] = ( n & (1 << i) ) ? 1 : 0;
        }
        //cout << (int)(in.to_ulong()) << endl;
        //for (int i = 0; i < )
        for(int i = 0; i < 8; i++)
            out[24 + i] = in[i];
        for(int i = 8; i < 16; i++) out[8 + i] = in[i];
        for(int i = 16; i < 24; i++) out[i - 8] = in[i];
        for(int i = 24; i < 32; i++) out[i - 24] = in[i];
        int res = (int)(out.to_ulong());
        cout << n << " converts to " << res << endl;
    }
    return 0;
}
