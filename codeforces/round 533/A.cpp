#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}	
	int best = 1000000000, best_t;
	for (t = 1; t <= 100; t++){
		int cost = 0;
		for (int i = 0; i < n; ++i)
		{
			//cout << cost << endl;
			if (abs(a[i] - t) > 1){
				cost += abs(a[i] - t) - 1;
			}
		}
		
		//cout << t << " " << cost << endl;

		if(cost  < best){
			best = cost;
			best_t = t;
		}
	}
	cout << best_t << " " << best << endl; 
	return 0;
}