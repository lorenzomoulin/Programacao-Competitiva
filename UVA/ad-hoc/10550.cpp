#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    while (true){
        int start, first, second, third;
        cin >> start >> first >> second >> third;
        if (!start && !first && !second && !third)
            break;
        int res = 1080;
        res += first > start ? 360 - 9 * (first - start) : 9 * (start - first);
        res += first > second ? 360 - 9 * (first - second) : 9 * (second - first);
        res += third > second ? 360 - 9 * (third - second) : 9 * (second - third);
        cout << res << endl;
    }
    return 0;
}
