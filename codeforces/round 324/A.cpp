#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t;
	cin >> n >> t;
	if (n == 1 && t == 10)
		cout << -1 << endl;
	else{
		cout << t;
		if (t != 10)
			for (int i = 1; i <= n -1; i++)
				cout << 0;
		else
			for (int i = 1; i <= n -2; i++)
				cout << 0;
		cout << endl;
	}
	return 0;
}