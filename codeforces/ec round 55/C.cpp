#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int main(){
    int n, m, t;
    cin >> n >> m;
    t = n;
    while(t--){
        vvi team[m]; vi skills;
        for (int i = 0; i < n; i++){
            int si, ri; cin >> si >> ri;
            team[si - 1].push_back(ri);   
        }
           
    }
    return 0;
}
