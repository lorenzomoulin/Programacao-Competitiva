#include <iostream>
#include <cstring>
using namespace std;



int main(){
	string a;
	char dat[256] = {0};
	dat['B'] = dat['F'] = dat['P'] = dat['V'] = '1';
	dat['C'] = dat['G'] = dat['J'] = dat['K'] = dat['Q'] = dat['S'] = dat['X'] = dat['Z'] = '2';
	dat['D'] = dat['T'] = '3';
	dat['L'] = '4';
	dat['M'] = dat['N'] = '5';
	dat['R'] = '6';
	while (cin >> a){
		string res = "";
		if (dat[a[0]])
			{
				res += dat[a[0]];
			}
		for (int i = 1; i < a.size(); ++i)
		{
			if (dat[a[i]] && dat[a[i]] != dat[a[i - 1]])
			{
				res += dat[a[i]];
			}
		}
		cout << res << endl;
	}
	return 0;
}