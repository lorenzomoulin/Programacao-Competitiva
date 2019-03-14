#include <iostream>
#include <cstring>
using namespace std;
/*
a 3
W 10
A 100
, 10
k 7
. 3
I 13
*/
int main(){
	int n;
	cin >> n;
	while(n--){
		int k;
		int dat[256] = {0};
		cin >> k;
		for (int i =0 ; i < k; i++){
			char temp;
			int value;
			cin >> temp >> value;
			//cout << temp << " " << value << endl;
			dat[(int)temp] = value;
		}
		int m;
		cin >> m;

		int res = 0;
		//cout << m << endl;
		getchar();
		for (int i = 0; i < m; i++){
			string temp;
			getline(cin, temp);
			//cout << temp << endl;
			for (int j = 0; j < temp.size(); j++){
				if (temp[j] > 255 || temp[j] < 0)
					continue;
				res += dat[temp[j]];
			}
		}
		
		printf("%.2f$\n", res/100.0);
		
	}
	return 0;
}