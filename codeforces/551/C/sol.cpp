#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
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
    if (n % 2)
        cout << ":(\n";
    else {
    
        int left = 0;
        int right = 0;
        trav(a, s){
            if (a == '(')
                left++;
            if (a == ')')
                right++;
        }
        left = n/2 - left;
        right = n/2 - right;
        int i = 0;
        while(left && i < n){
            if (s[i] == '?')
                s[i] = '(', left--;
            i++;
            
        }
        if (i >= n && left){
            cout << ":(\n";
            return 0;
        }
            
        i = 0;
        while (right && i < n){
             if (s[i] == '?')
                s[i] = ')', right--;
            i++;
            
        }
        if (i >= n && right){
            cout << ":(\n";
            return 0;
        }
        stack<int> pilha;
        pilha.push(s[0]);
        for(int i = 1; i < sz(s); ++i){
            if (!sz(pilha))
            {
                    cout << ":(\n";
                    return 0;
            }
            if (s[i] == ')' )
                pilha.pop();
            else 
                pilha.push(s[i]);
        }
        if (sz(pilha))
            cout << ":(\n";
        else 
            cout << s << endl;
    }
    return 0;
}
