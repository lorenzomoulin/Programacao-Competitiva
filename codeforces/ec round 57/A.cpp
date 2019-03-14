#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		ll l, r;
		cin >> l >> r;
		cout << l << " " << 2*l << endl;
	}
	return 0;
}