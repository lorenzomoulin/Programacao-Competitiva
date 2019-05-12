#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef pair<int, int> ii;

bool comp(ii a, int b){
    return a.second <= b;
}

int main(){
    int n, m, a1;
    cin >> n >> m;
    ii a[n];
    cin >> a1;
    a[0] = ii(1, a1);
    for(int i = 1; i < (n - 1); i++){
        int ai;
        cin >> ai;
        a[i] = ii(a[i - 1].second, ai);
    }
    a[n - 1] = ii(a[n - 2].second, INF);
    int premios[n];
    for (int i = 0; i < n; ++i)
        cin >> premios[i];
    while(m--){
        int o;
        cin >> o;
        ii * low = lower_bound(a, a + n, o, comp);
        cout << premios[low - a];
        if (m)
            cout << " ";
        else
            cout << "\n";
    }
    return 0;
}
