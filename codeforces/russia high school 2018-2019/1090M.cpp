#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int cont = 1, max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] ;
    } 
    //cout << a[0] <<  " ";
    for (int i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            //cout << a[i] << " ";
            cont++;
        }
        else{
            if (cont > max){
                max = cont;
                    
            }
            //cout << endl << a[i] << " ";
            cont = 1;
        }
       
    }
    //scout << endl;
    max > cont ? cout << max << endl: cout << cont << endl;
    return 0;
}
