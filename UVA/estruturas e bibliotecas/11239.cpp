#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(s) (int)s.size()
using namespace std;

bool cmp (pair<int, string> a, pair<int, string> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(){
    string s;
    getline(cin, s);
    //cout << s << endl;
    while(s.compare("0")){
        map<string, vector<string>> alunos;
        map<string, int> projetos;
        string projeto;
        while(s.compare("1")){
            string temp = "";
            for(int i = 0; i < sz(s); ++i)
                temp += toupper(s[i]);
            //cout << temp << "\n";
            if(!temp.compare(s)){
                projeto = temp;
                projetos[projeto] = 0;
            }
            else{
                
                vector<string>::iterator it;

                it = find (all(alunos[s]), projeto);
                if (it == alunos[s].end()){
                    alunos[s].pb(projeto);
                    projetos[projeto]++;
                }
                //cout << alunos[s].size() << endl;
            }
            getline(cin, s);
            
        }
        map<string, vector<string>>::iterator it;
        for(it = alunos.begin(); it != alunos.end(); ++it){
            if((int)it->second.size() > 1){
                //cout << "entrou\n";
                for(auto i: it->second){
                    projetos[i]--;
                }
            }
            
        }
        
        vector<pair<int, string>> res;
        for(auto i: projetos){
            //cout << i.first << " " << i.second << "\n"; 
            res.pb(pair<int, string>(i.second, i.first));
        }
        
        sort(res.begin(), res.end(), cmp);
        for(auto i: res){
            cout << i.second <<  " " << i.first << "\n";
        }
        getline(cin, s);
    }
    return 0;
}
