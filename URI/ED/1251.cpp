#include <bits/stdc++.h>

using namespace std;

vector<pair<char, int>> vpci;
int table[256];

bool myfunction (pair<char, int> i,pair<char, int> j) {
    if(i.second < j.second){
        return true;
    }
    else if(i.second > j.second){
        return false;
    }   
    else{
        return (i.first > j.first);
    }    
}

int main(){
    string s;
    cin >> s;
    while (true){
        vpci.clear();
        for (int i = 0; i < 256; i++)
            vpci.push_back(make_pair(i, 0));
        for(int i =0 ; i < s.size(); i++){
            vpci[s[i]].second++;
        }
        sort(vpci.begin(), vpci.end(), myfunction);
        for (int i = 0; i < vpci.size(); i++){
            if (vpci[i].second > 0)
                printf("%d %d\n", vpci[i].first, vpci[i].second);
        }
        if(cin >> s)
            cout << endl;
        else
            break;
    }
    return 0;
}
