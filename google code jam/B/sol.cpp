#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    int t, cases = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << cases << ": ";

        for(int i = 0; i < s.size(); i++)
            s[i] == 'E'? cout << "S": cout << "E";

        cout << endl;
        cases++;
    }
    return 0;
}
