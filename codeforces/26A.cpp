#include <iostream>
#include <set>
using namespace std;

bool almostprime(int n){
    set<int> a;
    int i = 2;
    while (n > 1){
        while (n % i == 0){
            n /= i;
            a.insert(i);
        }
        i++;
    }
    return a.size() == 2;
}

int main(){
    int n; cin >> n;
    int cont = 0;
    for (int i = 1; i <= n; i++){
        if (almostprime(i)) cont++;
    }
    cout << cont << endl;
    return 0;
}
