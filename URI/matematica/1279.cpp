#include <bits/stdc++.h>
using namespace std;
bool div3(string s){
    int sum = 0;
    for(auto &a: s)
        sum += (a - '0');
    return (sum % 3 == 0); 
}

bool div4(string s){
    int sum = 0;
    sum += (s[(int)s.size() - 1] - '0') + 10*(s[(int)s.size() - 2] - '0');
    return (sum % 4 == 0);
}

bool div5(string s){
    return ((s[(int)s.size() - 1] - '0') % 5 == 0);
}

bool div11(string s){
    int sum_odd = 0, sum_even = 0;
    for(int i = 0; i < (int)s.size(); i += 2)
        sum_odd += (s[i] - '0');
    for(int i = 1; i < (int)s.size(); i += 2)
        sum_even += (s[i] - '0');

    return ((sum_odd - sum_even) % 11  == 0);
}

bool div100(string s){
    return (s[(int)s.size()-1] == '0' && s[(int)s.size() - 2] == '0');   
}

bool div400(string s){
    return (s[(int)s.size()-1] == '0' && s[(int)s.size() - 2] == '0' && (s[(int)s.size() - 3] - '0') % 2 == 0);
}

using namespace std;

int main(){
    string s;
    cin >> s;
    while(true){
        
        bool ordinary = true;
        if (div4(s) && !div100(s) || div400(s))
            cout << "This is leap year.\n", ordinary = false;
        if (div5(s) && div3(s))
            cout << "This is huluculu festival year.\n", ordinary = false;
        if(div11(s) && div5(s) && (div4(s) && !div100(s) || div400(s)))
            cout << "This is bulukulu festival year.\n", ordinary = false;
        if (ordinary)
            cout << "This is an ordinary year.\n";
        
        
        if (cin >> s)
            cout << "\n";
        else
            break;
    }
    return 0;
}
