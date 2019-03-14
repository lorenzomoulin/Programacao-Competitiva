#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int T[255];
	for (int i = 0; i < 255; ++i)
		T[i] = 0;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int count = 0;
	int t = 1;
	for (int i = 1; i < n; i++)
	{
		if (t == k){
			T[s[i - k]]++;
			i++;
			t = 1;
		}
		if (s[i] != s[i - 1]){
			t = 1;

		}
		else{
			t++;
		}
		
	}

	int max = 0;
	for (int i = 0; i < 255; ++i)
	{
		//cout << T[i] << endl;
		if(T[i] > max)
			max = T[i];
	}
	
	cout << max << endl;

	return 0;
}