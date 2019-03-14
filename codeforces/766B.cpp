#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a;
    while (n--){
        int i; cin >> i;
        a.push_back(i);
        
        
    }
    sort(a.begin(), a.end());
    n = a.size();
    for (int i = n - 1; i >= 2; i--){
        if (a[i - 1] + a[i - 2] > a[i] && a[i - 1] + a[i] > a[i - 2]  && a[i] + a[i - 2] > a[i - 1] )  { cout << "YES\n"; return 0;}
    }
    
    cout << "NO\n";
    return 0;
}
