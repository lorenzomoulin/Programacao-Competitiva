#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct jogador{

    int tempo;
    string time;
    int n;
};

bool cmp(pair<int, jogador> a, pair<int, jogador> b){
    return a.second.tempo  < b.second.tempo;
}

int main(){
    string h, a;
    cin >> h >> a;
    map<int, jogador> p;
    int n;
    cin >> n;
    while(n--){
        int i;
        char t;
        int time;
        char card;
        cin >> time >> t >> i >> card;
        map<int, jogador>::iterator it;
        
        it = p.find(i);
        if(it != p.end()){
            bool menor = it->second.n < 2;
            if (menor )
                cout << it->first << " nao tem cartao vermelho tempo: " << time << endl;
            card == 'r'? it->second.n+=2: it->second.n++;
            if (menor && it->second.n >= 2)
                it->second.tempo = time;
            
        } 
        else {
            jogador temp;
            temp.tempo = time;
            if(t == 'h')
                temp.time = h;
            else
                temp.time = a; 
            card == 'r'? temp.n = 2: temp.n = 1;
            p.insert(pair<int, jogador>(i, temp));
        }
        
    }
    vector<pair<int ,jogador>> vj;
    trav(a, p){
        vj.pb(a);
        //cout << a.second.n << endl;
    }
    sort(all(vj), cmp);
    rep(i, 0, sz(vj) - 1){
        if(vj[i].second.n > 1)
            cout << vj[i].second.time << " " << vj[i].first << " " << vj[i].second.tempo << endl;
    }
    if(vj[sz(vj) - 1].second.n > 1)
            cout << vj[sz(vj) - 1].second.time << " " << vj[sz(vj) - 1].first << " " << vj[sz(vj) - 1].second.tempo;
    return 0;
}
