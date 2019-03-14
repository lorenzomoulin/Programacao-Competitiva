#include <iostream>
#include <cstring>
using namespace std;
int n;

void insert(int *a, int pos, int x){
    if (a[pos] == -1){ a[pos] = x; return;}
    if (x > a[pos]) insert(a, pos*2+1, x);
    if (x < a[pos]) insert(a, pos*2, x);
}

void preorder(int *a, int pos){
    if (pos > n)   return;
    cout << " " << a[pos];
    preorder(a, pos * 2);
    preorder(a, pos*2 + 1); 
}

void inorder(int *a, int pos){
    if (pos > n)    return;
    inorder(a, pos*2);
    cout << " " << a[pos];
    inorder(a, pos*2 + 1); 
}

void posorder(int *a, int pos){
    if (pos > n)    return;
    posorder(a, pos*2);
    posorder(a, pos*2 + 1);
    cout << " " << a[pos];
}

int main(){
    int c; cin >> c;
    int cont = 1;
    while (c--){
        cin >> n;
        int a[n + 1];
        memset(a, -1, sizeof(int));
        for(int i = 1; i <= n; i++){  
            int b;
            cin >> b;
            insert(a, 1, b);
            
        }
        cout << "Case " << cont << ":\n";
        cout << "Pre.:";
        preorder(a, 1);
        cout << endl;
        cout << "In.:";
        inorder(a, 1);
        cout << endl;
        cout << "Pos.:";
        posorder(a, 1);
        cout << endl;
        cont++;
    }
    return 0;
}
