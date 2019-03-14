#include <iostream>
using namespace std;

int lucky[] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};

int main(){
    int n;
    cin >> n;
    bool al = false;
    for (int i = 0; i < 12; i++){
        if(n % lucky[i] == 0){  al = true; break;}
    }
    al? cout << "YES\n":cout << "NO\n";
    return 0;
}
