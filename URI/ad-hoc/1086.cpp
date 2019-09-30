#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
int l, k, m, n, tabua[(int)1e5 + 9], dat1[(int)1e4 + 1], dat2[(int)1e4 + 1];

int main (){
    while (true){      
        cin >> m >> n;
        if (m + n == 0)  {break;}
        cin >> l >> k;
        
        memset(dat1, 0 , sizeof dat1);
        memset(dat2, 0 , sizeof dat2);
        for (int i = 0; i < k; i++) cin >> tabua[i], dat1[tabua[i]]++, dat2[tabua[i]]++;
        
        if ((m*100)%l && (n*100)%l) {
            cout << "impossivel\n";
            continue;
        }
        sort(tabua, tabua + k);
        int res, nt1 = INF, nt2 = INF;
        if ((m*100)%l == 0){
            int h = n, q = (m*100)/l, cont = 0;
            nt1 = 0;
            for (int i = k - 1; i >= 0 && cont < q; i--){
                if (tabua[i] <= h && dat1[tabua[i]] > 0){
                    if (tabua[i] == h)
                        dat1[tabua[i]]--, cont++, nt1++;
                    else {
                        if (tabua[i] == (h - tabua[i]) && dat1[h - tabua[i]] > 1)
                            dat1[tabua[i]]--, dat1[h - tabua[i]]--, cont++, nt1 += 2;
                        else if (tabua[i] != (h - tabua[i]) && dat1[h - tabua[i]] > 0)
                            dat1[tabua[i]]--, dat1[h - tabua[i]]--, cont++, nt1 += 2;
                    }
                    
                }
            }
            //cout << "q = " << q << " cont = " << cont << '\n'; 
            if (cont < q)
                nt1 = INF;
            //cout << "nt1 = " <<  nt1 << '\n';
        }
        if ((n*100)%l == 0){
            int h = m, q = (n*100)/l, cont = 0;
            nt2 = 0;
            
            for (int i = k - 1; i >= 0 && cont < q; i--){
                if (tabua[i] <= h && dat2[tabua[i]] > 0){
                    if (tabua[i] == h)
                        dat2[tabua[i]]--, cont++, nt2++;
                    else{
                        if (tabua[i] == (h - tabua[i]) && dat2[h - tabua[i]] > 1)
                            dat2[tabua[i]]--, dat2[h - tabua[i]]--, cont++, nt2 += 2;
                        else if (tabua[i] != (h - tabua[i]) && dat2[h - tabua[i]] > 0)
                            dat2[tabua[i]]--, dat2[h - tabua[i]]--, cont++, nt2 += 2;
                            
                    }
                }
            }
            if (cont < q)
                nt2 = INF;
            //cout << "nt2 = " <<  nt2 << '\n';
        }
        
        res = min(nt1, nt2);
        res == INF ? cout << "impossivel\n" : cout << res << '\n';//) << '\n'; 
        //cout << '\n';
    }
    return 0;
}
