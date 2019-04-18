#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = INF;
    char alfabeto[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string genoma = "ACTG";
    for (int i = 0 ; i < n - 3; ++i){
        
        int temp = 0;
        for (int j = i; j < i + 4; j++){
            if (s[j] < genoma[j - i]){
                temp += min(genoma[j - i] - s[j], s[j] + 26 - genoma[j - i]);
            }
            
            else if (s[j] > genoma[j-i]){
                temp += min(s[j] - genoma[j - i] , genoma[j - i] + 26 - s[j]);
            }
            
                
            //temp += min(abs(s[]), abs(genoma[j - i] + 26 - s[i] ));
        }
        res = min(res, temp);
    }
    cout << res << "\n";
   return 0;
}
