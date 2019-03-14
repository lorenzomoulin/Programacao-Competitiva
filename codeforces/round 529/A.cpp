#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	string res = "";
	int cont = 0;
	for (int i = 0; i < n; i += cont){
		res += a[i];
		//cout << i << endl;
		cont++;
	}
	cout << res << endl;
    return 0;
}
