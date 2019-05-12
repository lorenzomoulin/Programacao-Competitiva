#include <bits/stdc++.h>
#define left(i) (i << 1)
#define right(i) ((i << 1) + 1)
#define rep(i, a, b) for(int i = a; i  <(b); i++)
using namespace std;

int a[100000], n;

struct tree{
    int v;
    tree *l;
    tree *r;
};

void insere(int i, int v){
    cout << i << endl;
    if (a[i] == -1){
        a[i] = v;
        return ;
    }
    if (v > a[i]){
        insere(right(i), v);
        
    }
    else
        insere(left(i), v);
}

void pre(int i){
    cout << i << endl;
    if (a[i] != -1){
        cout << " " << a[i];
        pre(left(i));
        pre(right(i)); 
    }
    return;
}

void in(int i){
    if (a[i] != -1){
        in(left(i));
        cout << " " << a[i];
        in(right(i));
    }
    return ;
}

void pos(int i ){
    if (a[i] != -1){
        pos(left(i));
        pos(right(i));
        cout << " " << a[i];
    }
    return;
}

int main(){
    int c, caso = 1;
    cin >> c;
    while(c--){
        cout << "Case " << caso << ":\n";
        memset(a, -1, sizeof a);
        cin >> n;
        rep(i, 1, n + 1){
            int v;
            cin >> v;
            insere(1, v);
        }
        cout << "Pre.:";
        pre(1);
        cout << "\nIn..:";
        in(1);
        cout << "\nPost.:";
        pos(1);
        cout << "\n\n";
        caso++;
    }
    return 0;
}
