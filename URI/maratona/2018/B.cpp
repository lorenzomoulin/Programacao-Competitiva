#include <iostream>
#include <cmath>

using namespace std;

int n;
int lt;
//busca binaria no vetor de arcos acumulados    
int bs(int i, int ini, int fim, int arcos[], int valor){
    int mid = (ini + fim)/2;
    //cout << "ini: " << ini << " mid: " << mid << " fim: " << fim << endl;
    //for (int j = ini; j <= fim; j++)    cout << arcos[j] - arcos[i]<< " ";
    //cout << endl;
    //cout << arcos[mid] - arcos[i] << " \n";
    if (arcos[mid] - arcos[i] == valor)    return mid;
    if (ini > fim) return -1;
    int idx;
    if (valor > arcos[mid] - arcos[i]) idx = bs(i, mid+1, fim, arcos, valor);
    else if (valor < arcos[mid] - arcos[i]) idx = bs(i, ini, mid-1, arcos, valor);
    return idx;
}

int main(){
    cin >> n;
    int i = n;
    int arcos[n + 1] = {0};lt=0;
    for (i = 1; i <= n; i++){
        int l;
        cin >> l;
        arcos[i] = l + arcos[i-1];
        lt += l;
    }
    //cout << lt << endl;
    if (lt%2){cout << "N\n"; return 0;}
    /*for (i = 0; i<=n; i++)
        cout << arcos[i] << " ";
        cout << endl;*/
    int idx1, idx2;
    for (i = 0; i < n; i++){
        idx1 = bs(i, i, n, arcos, lt/2 );
        //cout << "idx1 " << i << ": "<< idx1 << endl;
        if (idx1 != -1){
            for (int j = i + 1; j < n; j++){
                
                idx2 = bs(j, j, n-1, arcos, lt/2);
                //cout << "idx2 " << j << ": "<< idx2 << endl;
                if (idx2 != -1){
                    //cout << "arcos: " << arcos[idx1] - arcos[i] << " " << arcos[idx2]  << endl; 
                    if (abs((arcos[idx1])- (arcos[idx2] )) > 0 && abs(arcos[idx1] - (arcos[idx2] - arcos[j])) == abs(lt/2 - (arcos[idx2] - arcos[j]))){
                        cout << "Y\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "N\n";
    
    return 0;    
}
