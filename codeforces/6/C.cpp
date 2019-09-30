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
    int n;
    cin >> n;
    int bar[n];
    rep(i, 0 ,n)cin>> bar[i];
    
    int a = 0, b = 0, i = 0, j = n - 1;
    while (i < j){
        if (bar[i] < bar[j]){
            bar[j] -= bar[i];bar[i] = 0;
            i++;
            a++;
            if (i == j){
                b++;
                break;
            } 
        }
        else if (bar[i] > bar[j]){
            bar[i] -= bar[j];bar[j] = 0;
            j--;
            b++;
            if (i == j){
                a++;
                break;
            } 
        }
        else{
            i++, j--;
            a++, b++;
            if (i == j){
                a++;
                break;
            }
        }
    }
    cout << a << " " << b << '\n';
    return 0;
}
