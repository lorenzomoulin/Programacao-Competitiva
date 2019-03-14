#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int horas = n / 3600;
    n -= horas*3600;
    int min = n / 60;
    n -= min*60;
    cout << horas << ":" << min << ":" << n << endl;
    return 0;
}
