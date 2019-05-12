#include <bits/stdc++.h>

using namespace std;

int main(){
    int freq[2001];
    memset(freq, 0, sizeof freq);
    int n ;
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        freq[a]++;
        
    }
    for(int i = 1; i <= 2000; i++){
        if (freq[i]){
            cout << i << " aparece " << freq[i] << " vez(es)\n";
        }
    }
    return 0;
}
