#include <bits/stdc++.h>
#define FOR(i, n) for (int i =0; i < n; i++)
#define debug(a) FOR(i, a.size()) cout << a[i] << " "; cout << endl;
using namespace std;

int main(){
    int t;
    cin >>t ;
    getchar();
    while(t--){
        vector<int> seq; vector<float> a;
        char temp;
        do {
            int b;
            scanf("%d%c", &b, &temp);
            seq.push_back(b);
        }while(temp != '\n');
        //debug(seq)
        do {
            float b;
            scanf("%f%c", &b, &temp);
            a.push_back(b);
        }while (temp != '\n');
        //debug(a);
        sort(a.begin(), a.end());
        for (int i = 0; i < seq.size(); i++){
            printf("%f\n", a[seq[i] - 1]);
        }
        cout << endl;
    }
    return 0;
}
