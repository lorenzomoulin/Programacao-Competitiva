#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#define pb push_back
using namespace std;

template <typename T>
T extgcd(T a, T b, T& x, T& y){
    if (b == 0){
        x = 1; y = 0; return a;
    }
    else {
        T g = extgcd(b, a%b, y, x);
        y -= a / b * x; return g;
    }
}

template <typename T>
void diophantine(T a, T b, T c, T& x, T& y){
    T d = extgcd(a, b, x, y);
    x *= c / d; y *= c / d;  
}

bool prime(int n){
    if (n < 0)  n = -n;
    if (n < 5 || n % 2 == 0 || n % 3 == 0)
        return (n == 2 || n == 3);
    int maxp = sqrt(n) + 2;
    for (int p = 5; p < maxp; p += 6){
        if (p < n && n % p == 0)    return false;
        if (p + 2 < n && n % (p + 2) == 0)  return false;
        
    }
    return true;
}

int main(){ 
    int n;
    cin >> n;
    int x, y;
    diophantine(1, 1, n, x, y);
    vector<pair <int, int>> a;
    pair<int, int> b = make_pair(x, y);
    if (x > 1 && y > 1)
        a.pb(b);
    while (y > 1){
        y -= 1;
        x += 1;
        if (x > 1 && y > 1)
            a.pb(make_pair(x, y));
    }
    for (int i = 0; i < a.size(); i++){
        if (!prime(a[i].first) && !prime(a[i].second)){
            cout << a[i].first << " " << a[i].second << endl;
            break;
        } 
    }
    return 0;
}
