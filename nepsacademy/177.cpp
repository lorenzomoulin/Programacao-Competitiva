#include <iostream>

using namespace std;

int main(){
    int x, s = 0;
    
    for(int i = 0; i < 3; i++){
        cin >> x;
        s += x % 10 == 5 || x % 2 == 0;
    }

    cout << s << "\n";
    return 0;
}
