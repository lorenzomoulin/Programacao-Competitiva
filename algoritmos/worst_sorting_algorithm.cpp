#include <bits/stdc++.h>

using namespace std;

bool sorted(vector<int> &a){
    
    for(int i = 1; i < (int)a.size(); ++i)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    
    return true;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    while(n--){
        cin >> a[n];
    }
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    while(!sorted(a)){
        shuffle(a.begin(), a.end(), default_random_engine(seed));
    }
    for(auto &b: a){
        cout << b << " ";
    }
    cout << "\n";
    return 0;
}
