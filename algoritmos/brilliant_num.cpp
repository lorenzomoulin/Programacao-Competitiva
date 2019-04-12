#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull reverse_num(ull n){
    ull res = 0;
    while(n > 0){
        res *= 10;
        res += (n % 10); 
        n /= 10;
    }
    return res;
}

int main(){
    int i = 0, j = 0;
    
    unsigned long long int res, nums = 1;
    //cout << reverse_num(1234) << endl;
    while (i != 10000){
        int g = ((nums + reverse_num(nums)) % 13) == 0;
        if (g){
            res = nums;
            //cout << res << " " << reverse_num(res) << endl;
            i++;
        }
        nums ++;
        j++;
    }
    cout << j << endl;
    return 0;
}
