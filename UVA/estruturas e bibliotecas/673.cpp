#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    string buffer;
    getline(cin , buffer);
    while(t--){
        stack<char> s;
        string in;
        getline(cin, in);
        
        bool flag = true;
        
        //cout << in << endl;
        for(int i = 0; i  <in.size(); i++){
            
            if (in[i] == '[' or in[i] == '(')
                s.push(in[i]);
            else if(in[i] == ')'){
            
                if(s.size() and s.top() == '(')
                    s.pop();
                else{
                    flag = false;
                    break;
                }
            }
            else{
                if(s.size() and s.top() == '[')
                    s.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag && !s.size())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

