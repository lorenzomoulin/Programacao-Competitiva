#include <bits/stdc++.h>
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int MAXD = 123;
const int MAXK = 112345;
const int mod = 1e9+7;
 
char ent[MAXK];
int d, strSize;
int pd[MAXK][MAXD][2];
string numStr;
 
int rec(int cur, int sum, int last_digit_gt)
{
    // cout << last_digit_gt << " -- " << sum << endl;
    if(cur==strSize){
        //cout << numStr << endl;
        if(sum==0) return pd[cur][sum][last_digit_gt] = 1;
        return pd[cur][sum][last_digit_gt] = 0;
    }
 
    if(pd[cur][sum][last_digit_gt]!=-1)
        return pd[cur][sum][last_digit_gt];
 
    int acum = 0;
    int lim = last_digit_gt ? (ent[cur]-'0') : 9;
    for(int i=0; i<=lim; i++){
        // cout << cur << " // " << i << endl;
        //numStr += i + '0';
        int next_last_digit = last_digit_gt && (i == lim);
        acum += rec(cur+1, (sum+i)%d, next_last_digit);
        //numStr.pop_back();
        acum = acum%mod;
    }
 
    return pd[cur][sum][last_digit_gt] = acum;
}
 
int main()
{
    scanf("%s\n%d", ent, &d);
    strSize = strlen(ent);
 
    memset(pd, -1, sizeof(pd));
 
    int resp = 0;
    for(int i=0; i<(ent[0]-'0'); i++){
        //numStr += i + '0';
        resp += rec(1,i%d,0);
        resp = resp%mod;
       // numStr.pop_back();
    }
    //numStr += ent[0];
    resp += rec(1,(ent[0]-'0')%d,1);
    resp = resp%mod;
    //numStr.pop_back();
    //cout << endl << endl;
    cout << resp-1 << '\n';
 
    // for(int i=0; i<=10000; i++)
    //  cout << i;
    // cout << endl << "12";
 
    return 0;
}
