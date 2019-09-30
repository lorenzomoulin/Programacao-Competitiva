#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct time{
    string nome;
    int sg, pontos;
};

bool cmp (struct time a, struct time b){
    if (a.pontos == b.pontos){
        if (a.sg == b.sg){
            return a.nome.compare(b.nome) < 0;
        }
        else
            return a.sg > b.sg;
    }
    else
        return a.pontos > b.pontos;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    struct time times[4];
    int n;
    
    rep(i, 0, 4){
        cin >> times[i].nome;
        times[i].sg = times[i].pontos = 0;
        //cout << times[i].nome << '\n';
    }
    cin >> n;
    rep (i, 0, n){
        string time1, time2;
        int g1, g2;
        cin >> time1 >> g1 >> time2 >> g2;
        
        for(int j = 0; j < 4; j++){
            if (!(times[j].nome.compare(time1))){
                if (g1 > g2)
                    times[j].pontos += 3, times[j].sg += g1 - g2;
                else if (g1 < g2)
                    times[j].sg += g1 - g2;
                else 
                    times[j].pontos += 1, times[j].sg += g1 - g2;
            } 
            else if (!(times[j].nome.compare(time2))){
                if (g2 > g1)
                    times[j].pontos += 3, times[j].sg += g2 - g1;
                else if (g2 < g1)
                    times[j].sg += g2 - g1;
                else 
                    times[j].pontos += 1, times[j].sg += g2 - g1;
            }   
        }
    }
    sort(times, times + 4, cmp);
    cout << times[0].nome << '\n';
    cout << times[1].nome << '\n';    
    return 0;
}
