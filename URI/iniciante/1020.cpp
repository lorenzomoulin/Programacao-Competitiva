#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ano = n / 365;
    n -= ano*365;
    int mes = n / 30;
    n -= mes*30;
    cout << ano << " ano(s)\n" << mes << " mes(es)\n" << n << " dia(s)" << endl;
    return 0;
}
