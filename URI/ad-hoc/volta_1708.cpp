#include <bits/stdc++.h>

using namespace std;

template <typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
}

int main(){
    int x, y;
    cin >> x >> y;
    int tempo = ceil(1.0*ceil(1.0*lcm(x, y)/(y - x)) / x );
    cout << tempo << "\n";
    return 0;
}
