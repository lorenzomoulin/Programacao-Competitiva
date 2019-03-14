#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int a,n;
    
    cin >> a >> n;
    long long an = pow((double)a,(double)n);
    long long S = (a*(an-1)/(1-a) - n*an*a)/(1-a);
    cout << S << endl;
    return 0;
}
