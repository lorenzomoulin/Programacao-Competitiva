#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        bool nj = false;
        int a[n];
        bool b[n] = {false};
        for (int i = 0; i < n; i++){
                cin >> a[i];
        }
        for (int i = 1; i < n; i++){
            if (abs(a[i] - a[i - 1]) < 1 || abs(a[i] - a[i - 1]) > n - 1){
                cout << "Not jolly\n";
                nj = true;
                break;
            }
            b[abs(a[i] - a[i - 1])] = true;
        }
        if(nj)  continue;
        for (int i = 1; i < n; i++){
            if (b[i] == false){
                cout << "Not jolly\n";
                nj = true;
                break;
            }
        }
        if (!nj)
            cout << "Jolly\n";
    }
    return 0;
}
