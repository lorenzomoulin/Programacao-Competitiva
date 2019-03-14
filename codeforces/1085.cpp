#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int mid = (s.size() - 1) / 2;
	string res(1, s[mid]);
	int pos = mid;
	for (int i = 1, j = 1; i < s.size(); i++, j *= -1){
		pos += i*j;
		res += s[pos];
	}
	cout << res << endl;
 	return 0;
}