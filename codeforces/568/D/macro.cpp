#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    pair<ll, ll> seq[n];
    rep(i, 0, n){
        ll a;
        cin >> a;
        seq[i] = pair<ll, ll>(a, i);
    }
    
    sort(seq, seq + n);
    
    if (n == 2){
        cout << "1\n";
        return 0;
    }
    
    ll r = seq[2].first - seq[1].first;
    ll candidato = 0;
    
    vector<pair<ll, ll>> nseq;
    rep(i, 0, n){
        if (seq[i].second != candidato)
            nseq.push_back(seq[i]);
    }
    
    r = nseq[1].first - nseq[0].first;
    
    bool pode = true;
    rep(i, 2, sz(nseq)){
        if (nseq[i].first - nseq[i-1].first != r){
            pode = false;
            
            break;
        }
    }
    
    if (pode) {
        cout << candidato + 1 << '\n';
        return 0;
    }
     
    r = seq[1].first - seq[0].first;//cout << "candidato: " << candidato + 1 << '\n';
    //cout << "r = " << r << '\n';
    rep(i, 2, n){
        //cout << seq[i].first << " "  << seq[i-1].first << '\n';
        if((seq[i].first - seq[i-1].first) != r){
            candidato = seq[i].second;
            break;
        }
    }
    //cout << "candidato: " << candidato + 1 << '\n';
    nseq.clear();
    rep(i, 0, n){
        if (seq[i].second != candidato)
            nseq.push_back(seq[i]);
    }
    r = nseq[1].first - nseq[0].first;
    pode = true;
    rep(i, 2, sz(nseq)){
        if (nseq[i].first - nseq[i-1].first != r){
            pode = false;
            
            break;
        }
    }
    if (pode) 
        cout << candidato + 1 << '\n';
    else
        cout << "-1\n";
    return 0;
}
