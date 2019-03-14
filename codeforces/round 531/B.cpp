#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	int a[n], c[n] = {0};
	bool marcado[5001] = {false};
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		marcado[i] = false;
	}	
	for (int j = 0; j <= 5000; j++)
		marcado[j] = false;

	if(k > n){
		cout << "NO\n";
		return 0;
	}
	marcado[n] = false;
	int pos = 1;
	c[0] = 1;
	marcado[a[0]] = true;
	int cor = 1;
	for (int i = 1; i < n; i++){

		if (marcado[a[i]]){
			cor++;
			c[i] = cor;
			for (int j = 0; j <= 5000; j++)
				marcado[j] = false;
			marcado[a[i]] = true;
		}
		else{
			c[i] = cor;
			marcado[a[i]] = true;
		}
	}
	if (cor > k){
		cout << "NO\n";
		return 0;
	}
	if (cor < k){
		cor++;
		for (int i = 1; i < n; i++){
		
				c[i] = cor;
				cor++;
			
			if (cor > k)
				break;
		}
	}


	bool achou = false;
	for (int i = 0; i < n; i++){
		if (c[i] == k){
			achou = true;
			break;
		}
	}
	if (!achou ){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i = 0; i < n - 1; ++i)
	{
		cout << c[i] << " ";
	}
	cout << c[n - 1] << endl;
	return 0;
}
