#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, d;
	string s;
	cin >> n >> d >> s;
	int pos = 0, cont = 0;
	while(pos != n - 1)
	{
		int i = d;
		for ( i = d; i >= 1; --i)
		{
			if(s[pos + i] == '1')
			{
				pos += i;
				cont++;
				break;
			}
		}
		if(i == 0)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << cont << endl;
	return 0;
}