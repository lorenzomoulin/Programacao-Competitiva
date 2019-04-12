#include <bits/stdc++.h>
#define FOR(i, n) for (int i =0; i < n; i++)
#define debug(a) FOR(i, a.size()) cout << a[i] << " "; cout << endl;
using namespace std;

bool compare(string a, string b){   return stod(a) < stod(b);}

int main(){
    int t;
    cin >>t ;
    getchar();
    while(t--){
        vector<int> seq; vector<string> a;
        char temp;
        do {
            int b;
            scanf("%d%c", &b, &temp);
            seq.push_back(b);
        }while(temp != '\n');

        string res[seq.size() + 1];
        
        FOR(i, seq.size()){
            string abc;
            cin >> abc;
            a.push_back(abc);
        }
        FOR(i, seq.size()){
            res[seq[i]] = a[i];
        }

        for (int i = 1; i <= seq.size(); i++){
            cout << res[i] << endl;

        }
        if(t >= 1)
            cout << endl;
    }
    return 0;
}
