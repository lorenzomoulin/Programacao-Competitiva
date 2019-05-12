#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)x.size()
#define isnum(c) (c >= '0' && c <= '9')
#define endl "\n"
#define delimiter(c) (c == ',' || c == '\"' || c == ';' || c == ':' || c == '.' || c == '!' || c == '?' || c == '(' || c == ')' || c == ' ' || c == '\n' || c == '-')
using namespace std;

int main(){
    int contador[17];  
    memset(contador, 0, sizeof contador);
    char c;
    string s = "";
    set<string> ss;
    locale loc;
    while(scanf("%c", &c) != EOF){
        if((isnum(c)) || (delimiter(c))){
            if(sz(s)){
                rep(i ,0, sz(s)){
                    s[i] = tolower(s[i], loc);
                }
                
                if (ss.find(s) == ss.end()){
                    ss.insert(s);
                    contador[sz(s)]++;
                }
                s = "";
            }
        }
        else {
            s += c;
        }
    }
    rep(i, 0, 17){
        if (contador[i]){
            cout << contador[i] << " => " << i << endl; 
        }
    }
    return 0;
}
