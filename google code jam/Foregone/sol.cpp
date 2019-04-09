#include <bits/stdc++.h>

#define pf push_front
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);    
    int t, cases = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << cases << ": ";
        string c;
        cin >> c;
        deque<char> res;
        for(int i = c.size() - 1; i >= 0; i--){
            if(c[i] == '4')
                c[i]--, res.pf('1');
            else
                res.pf('0');
                
        }
        while(res.front() == '0'){
            res.pop_front();    
        }
        cout << c << " ";
        for(int i = 0; i < res.size(); i++)
            cout << res[i];
        cout << endl;
        
        cases++;
    }
    return 0;
}
