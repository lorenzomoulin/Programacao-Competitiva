#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    int amount = 0;
    while(t--){
        string s;
        cin >> s;
        int n;
        if (s.compare("donate") == 0){
            cin >> n;
            amount += n;
        }
        else{
            cout << amount << endl;
        }
           
    }

    return 0;
    
    
}


