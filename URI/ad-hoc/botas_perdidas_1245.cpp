#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        vector<int> l , r;
        while (n--){
            int a; char b;
            cin >> a >> b;
            if (b == 'D')
                r.push_back(a);
            else
                l.push_back(a);
        }   
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int res = 0;
        int ln = (int)l.size(), rn = (int)r.size();
        int i = 0, j = 0;
        while (i < ln && j < rn){
            if (l[i] == r[j])
                res++, i++, j++;
            else if (l[i] < r[j])
                i++;
            else
                j++;
        }
        cout << res << '\n';
    }
    return 0;
}
