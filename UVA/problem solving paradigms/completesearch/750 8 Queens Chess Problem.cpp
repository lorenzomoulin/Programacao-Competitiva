#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int row[8], t, a, b, lineCounter;

bool place(int r, int c){
    rep(i, 0, c){
        if (row[i] == r || abs(i - c) == abs(row[i] - r))
            return false;
    }
    return true;
}
void backtrack(int c){
    if (c == 8 && row[b] == a){
        printf("%2d      %d", ++lineCounter, row[0] + 1);
        rep(j, 1, 8){
            printf(" %d", row[j] + 1);
        }
        printf("\n");
    }
    rep(i, 0, 8){
        if (place(i, c)){
            row[c] = i; backtrack(c + 1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    scanf("%d", &t);
    while (t--){
        memset(row, 0, sizeof row); lineCounter = 0;
        scanf("%d %d", &a, &b); a--; b--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if (t)  printf("\n");
    }
   return 0;
}
