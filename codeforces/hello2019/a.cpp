#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string a;
	cin >> a;
	bool pode = false;
	for (int i = 0; i < 5; i++){
		string temp;
		cin >> temp;	
		if (temp[0] == a[0])
			pode = true;
		if (temp[1] == a[1])
			pode = true;		
	}
	if (pode)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}