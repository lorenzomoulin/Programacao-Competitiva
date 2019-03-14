#include <iostream>
using namespace std;
#include <vector>
#include <set>
#define pb push_back
void fib(int n){
    vector<int> f;
    set<int> a;
    f.pb(0); f.pb(1);
    for (int i = 2; f[i - 1] < n; i++)   f.push_back(f[i - 1] + f[i - 2]);
    
    int sum = 0;int      cont = 0;
    for (int i = f.size() - 1; i >= 0; i--){
        sum += f[i];
        if (sum == n){
            a.insert(f[i]);
            break;
        }   
        if (sum > n)
            sum -= f[i];
        else{
            a.insert(f[i]);
            cont++;
        }
    }
    if (sum != n){
        cout << "I'm too stupid to solve this problem" << endl;
        return;
    }
    if (a.size() == 1){
        cout << sum << " 0 0\n";
    }
    else if (a.size() == 2){
        for (auto i: a)
            cout << i << " ";
        cout << "0\n";
    }
    else if (a.size() == 3){
        set<int>::iterator it;
        for (it = a.begin(); it != a.end(); it++)
            cout << *it << " ";
        
        cout << endl;
    }
    else{
        cout << "I'm too stupid to solve this problem" << endl;
    }
}

int main(){
    int n; cin >> n;
    fib(n);
    return 0;
}
