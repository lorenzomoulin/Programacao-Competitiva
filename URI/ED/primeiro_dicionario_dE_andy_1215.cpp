#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "";
    set<string> sd;
    char c;
    bool tem = true;
    while (true){
        s = "";
        
        while (true){
            if (scanf("%c", &c) == EOF){
                tem = false;
                break;
            }
            if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
                break;
            s += tolower(c);
        }
        if (s.compare(""))
            sd.insert(s);
        if (!tem)
            break;
    }
    for (auto &a : sd){
        cout << a << '\n';
    }
    return 0;
}
