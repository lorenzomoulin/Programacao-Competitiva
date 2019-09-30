#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define trav(a, x) for(auto &a : x)
#define rep(i, a, b)    for(int i =a ; i <(b); ++i)
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;

int main(){
    string s;
    while(true){
        vector<vector<char>> cities;
        int res = INF, cidade;
        while(true){
            
            getline(cin, s);
            scanf("\n");
            //cout << s << endl;
            if (s[0] == 'e' || s[0] == '#'){
                //cout << res << "\n";
                break;
            
            }
            vector<char> city;
            trav(a, s)
                if (a != '/' && a != ',')
                    city.pb(a);
            cities.pb(city);
        }
        if (s[0] == 'e'){
            rep(i, 0, sz(cities)){
                int temp = 0;
                rep(j, 0, i){
                    rep(k, 0, 10){
                        if (cities[i][k] != cities[j][k])
                            temp++;
                    }
                }
                rep(j, i + 1, sz(cities)){
                    rep(k, 0, 10){
                        if (cities[i][k] != cities[j][k])
                            temp++;
                    }
                }
                if (temp <= res )
                    res = temp, cidade = i + 1;
            }
            cout << cidade << "\n";
        }
        if(s[0] == '#')
            break;
        
    }
    return 0;
}
