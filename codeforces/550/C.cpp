#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int> inc, dec;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    //monta increasing
    
    bool pegou[n];
    memset(pegou, false, sizeof pegou);
    int anterior = a[0];
    inc.push_back(a[0]); 
    pegou[0] = true;
    for(int i = 1; i  < n; i++){
        if (a[i] > anterior){
            inc.push_back(a[i]);
            anterior = a[i];
            pegou[i] = true;
        }
    }
    int pos;
    for (int i =  n - 1; i >= 0; i--){
        if(!pegou[i]){
            dec.push_back(a[i]);
            pegou[i] = true;
            anterior = a[i];
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if (!pegou[i]){
            if(a[i] < anterior){
                anterior = a[i];
                pegou[i] = true;
                dec.push_back(a[i]);
            }
        }
    }
   
    if(inc.size() + dec.size() != n)
        cout << "NO\n";
    else{
        cout << "YES\n";
        cout << inc.size() << endl;
        for (int i = 0; i < inc.size(); i++){
            if(i < inc.size() - 1)
                cout << inc[i] << " ";
            else
                cout << inc[i];
        }
        cout << endl << dec.size() << endl;
        for (int i = 0; i < dec.size(); i++){
            if(i < dec.size() - 1)
                cout << dec[i] << " ";
            else
                cout << dec[i];
        }
        cout << endl;
    }
    
    return 0;
}
