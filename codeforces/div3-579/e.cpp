#include <bits/stdc++.h>
using namespace std;

int v, n;

int main()
{
	cin >> v >> n;

	int total = v*n;
	for(int i=10; i<=90; i+=10)
	{
		cout << (int)ceil(total*(i/100.0));
		if(i<90)
			cout << ' ';
		else
			cout << '\n';
	}
	

	return 0;
}
