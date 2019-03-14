#include <iostream>

using namespace std;

struct tripla{
    int a,b,c;
};

int bs(int i, int l, int r, int a[], int v){
    int mid = l + (r-l)/2;
    int dif = a[mid] - a[i];
    if (l > r)  return -1;
    //for (int j = l; j <= r; j++) cout << a[j] - a[i] << " ";
    //cout << endl;
    if (dif == v)   return mid;
    int idx;
    if (v > dif) idx = bs (i, mid + 1, r, a, v);
    else if (v < dif) idx = bs (i, l, mid - 1, a, v);
    return idx;
}

int main(){
    int n;
    while (cin >> n){
    
        int arcos[n+1] = {0};
        int lt = 0;
        
        for (int i = 1; i <=n; i++){
            cin >> arcos[i];
            lt += arcos[i];
            arcos[i] += arcos[i-1];        
        }
        
        if (lt % 3){
            cout << "0\n";
            continue;
        }
        /*for (int i = 0; i <= n; i++){
            cout << arcos[i] << " ";
            
        }*/
        //cout << endl;
        int soma = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0, v = lt/3;
        //int triplas[]
        for (int i = 0; i < n; i++){
            idx1 = bs(i, i, n-1, arcos, v);
            //cout << "idx1 " << i << ": "<< idx1 << endl;
            if (idx1 != -1){
                idx2 = bs(i, i, n-1, arcos, 2*v);
                if (idx2 != -1) soma++;
              //  cout << "idx2 " << i << ": "<< idx2 << endl;
            }
            
            
            
            /*if (idx1 != -1 && idx2 != -1){
                idx3 = bs(idx1, idx1, n, arcos, v);
                cout << "idx3    " << i << ": "<< idx3 << endl;
                if (idx2 == idx3) soma++;
            }*/
            
            //i = idx1!=-1?idx1+1:i+1;
            
        }
        cout << soma << endl;
    }
    return 0;
} 
