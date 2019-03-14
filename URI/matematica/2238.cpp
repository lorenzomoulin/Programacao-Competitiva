#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi divisors(int n){
    vi div;
    for(int i = 1; i*i <= n; i++){
        if (n % i == 0) {
            if (n/i == i)   div.push_back(i);
            else    {
                div.push_back(i);
                div.push_back(n/i);     
            }
        }
    }
    return div;
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (c < a) {cout << "-1\n"; return 0;}
    vi div = divisors(c);
    for (int i = 0; i < div.size(); i++){
        /*if (div[i]%a == 0 && div[i]%b!=0 && div[i]%c==0 && div[i]%d!=0){
            cout << div[i] << endl;
            return 0;
        }*/
        cout << div[i] << " \n";
         
    }
    
    cout << "-1\n";
    return 0;
}
