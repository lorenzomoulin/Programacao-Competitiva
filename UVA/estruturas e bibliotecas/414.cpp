#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n = 1;
	cin >> n;
	while(n > 0){
		int a[n] = {0}, max = 0;
		//cout << n << endl;
		getchar();
		for(int i = 0; i < n; i++){
			string temp;
			getline(cin, temp);
			// /cout << temp << endl;
			for(int j = 0; j < temp.size(); j++){
				if(temp[j] == 'X')
					a[i]++;

			}
			if (a[i] > max)
				max = a[i];
			//cout <<  << endl;
		}
		int res = 0;
		for(int i = 0; i < n; i++){
			res += (max - a[i]);
		}
		//cout << n << endl;
		cout << res << endl;
		cin >> n;
		//cout << n << endl;
	}
	return 0;
}