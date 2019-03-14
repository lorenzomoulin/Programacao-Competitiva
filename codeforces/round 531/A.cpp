#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	cout << (n * (n + 1) / 2 % 2) << endl;
	return 0;
}