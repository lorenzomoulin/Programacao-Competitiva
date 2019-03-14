#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, p, sum = 0;
		cin >> n >> p;
		//cout << n << " " << p << endl;
		bool day[n + 1] = {false};
		int h[p];
		for (int i = 0; i < p; i++){
			cin >> h[i];
			int temp = h[i];
			for(int j = temp; j <= n; j += temp){
				if (j % 7 && j % 7 != 6 && !day[j]){
					sum++;
					day[j] = true;
				}
				//cout << "j: " << j << " soma: " << sum << endl;
			}
			//cout << "\n";
		}
		cout << sum << "\n";

	}
	return 0;
}