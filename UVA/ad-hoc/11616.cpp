#include <bits/stdc++.h>

using namespace std;

int rta[256];
string atr[3001];

int main(){
    string s;
    rta['I'] = 1;
    rta['V'] = 5;
    rta['X'] = 10;
    rta['L'] = 50;
    rta['C'] = 100;
    rta['D'] = 500;
    rta['M'] = 1000;
    atr[1] = "I";
    atr[2] = "II";
    atr[3] = "III";
    atr[4] = "IV";
    atr[5] = "V";
    atr[6] = "VI";
    atr[7] = "VII";
    atr[8] = "VIII";
    atr[9] = "IX";
    atr[10] = "X";
    atr[20] = "XX";
    atr[30] = "XXX";
    atr[40] = "XL";
    atr[50] = "L";
    atr[60] = "LX";
    atr[70] = "LXX";
    atr[80] = "LXXX";
    atr[90] = "XC";
    atr[100] = "C";
    atr[200] = "CC";
    atr[300] = "CCC";
    atr[400] = "CD";
    atr[500] = "D";
    atr[600] = "DC";
    atr[700] = "DCC";
    atr[800] = "DCCC";
    atr[900] = "CM";
    atr[1000] = "M";
    atr[2000] = "MM";
    atr[3000] = "MMM";
    while(cin >> s){
        if (s[0] >= '0' && s[0] <= '9'){
            deque<string> ds;
            for (int i = s.size() - 1; i >= 0; i--){
                ds.push_front(atr[(s[i] - '0')*((int)pow(10, s.size() - i - 1))]);
            }
            
            for (int i = 0; i < ds.size(); i++){
                cout << ds[i];
            }
            cout << endl;
        }
        else{
            int res = 0;
            bool flag = true;
            for(int i = 0; i < s.size(); i++){
                if(i < s.size() - 1 && rta[s[i]] < rta[s[i + 1]]){
                    res += rta[s[i + 1]] - rta[s[i]];
                    flag = false;
                    i++;
                }
                else{
                    res += rta[s[i]];
                    flag = true;
                }
            }
            
            cout << res << endl;
        }
    }    
    return 0;
}
