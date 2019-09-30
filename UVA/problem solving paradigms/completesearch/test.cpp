#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[1001], b[3], c[3];
    memset(a, 0, sizeof a);
    cin >> b[0] >> b[1] >> b[2];
    c[0] = b[0], c[1] = b[1], c[2] = b[2];
    sort(c, c + 3);
    a[b[0]] = 1, a[b[1]] = 2, a[b[2]] = 3;
    cout << a[c[0]] << '\n' << a[c[1]] << '\n' << a[c[2]] << '\n';
	return 0;
}
