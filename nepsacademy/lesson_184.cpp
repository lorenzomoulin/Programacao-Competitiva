#include <bits/stdc++.h>

using namespace std;

int lis(string c){
    multiset<int> s;
    multiset<int>::iterator it;
    for(auto &a : c){
        s.insert(a);
        it = s.upper_bound(a);
        if(it != s.end())   s.erase(it);
    }
    return s.size();
}

int main(){
    string s;
    cin >> s;
    cout << lis(s) << "\n";
    return 0;
}
