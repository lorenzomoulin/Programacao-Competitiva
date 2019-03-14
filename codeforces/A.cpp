#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int a[101];

int maior(int a[]){
    int m = 0;
    for (int i = 1; i <= 100; i++){
        a[i] > m? m = a[i]:m = m;
    }
    return m;
}

int main(){
    int n, k;
    memset(a, 0, sizeof(int));
    cin >> n >> k;
    set<int> tipos;
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        a[j]++;
        tipos.insert(j);
    }/*
    for (int i = 1; i <= 100; i++){
        if (a[i]){
            cout << i << ": " << a[i] << endl;
        }
    }   */
    int qtd_tipos = tipos.size();
    int max = maior(a);
    int min_pratos;
    if (max <= k)   min_pratos = 1;
    else{
        max % k == 0? min_pratos = max/k: min_pratos = max/k + 1;
    }
    //cout << min_pratos << endl;
    int cont = 0;
    int total_min = min_pratos*k;
    set<int>::iterator it;
    for (it = tipos.begin(); it != tipos.end(); it++){
        //cout << "tipo " << *it << ": " << a[*it] << endl;
        cont += total_min - a[*it];
    }
    cout << cont << endl;
    return 0;
}
