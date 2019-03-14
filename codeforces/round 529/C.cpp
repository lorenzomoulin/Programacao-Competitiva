#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

bool ehpot(int n){
	while (n % 2 == 0){
		n /= 2;
	}
	return n == 1;
}

vi convert(int n){
	vi bin;
	while(n >= 1){
		bin.push_back(n % 2);
		n /= 2;
	}
	return bin;
}	

int exp2(int n){
	int i = 1;
	for (int j = 0; j < n; j++)
		i *= 2;
	return i;
}

int main(){
	int n, k;
	cin >> n >> k;
	vi bin = convert(n);
	int min_number_power = 0;
	for (int i = 0; i < bin.size(); i++){
		if (bin[i] == 1)
			min_number_power++;
	}
	int max_number_power = 0;
	if (k < min_number_power){
		cout << "NO\n";
		return 0;
	}
	int res[k];
	for (int i = 0; i < bin.size(); i++){
		if(bin[i] == 1){
			max_number_power += exp2(i);
		}
	}
	if (k > max_number_power){
		cout << "NO\n";
		return 0;
	}
	if (k == min_number_power){
		cout << "YES\n";
		int j = 0;
		for (int i = 0; i < bin.size(); i++){
			if (bin[i] == 1){
				res[j] = exp2(i);
				j++;
			}
		}
		for (int i = 0; i < k - 1; i++){
			cout << res[i] << " ";
		}
		cout << res[n - 1] << endl;
		return 0;


	}
	if (k == 1 && !ehpot(n)){
		cout << "NO\n";
		return 0;
	}
	
	int falta = k - min_number_power;
	int x = 0;
	for (int i = 0; i < bin.size(); i++){
		if(bin[i] == 1){
			for (int j = 0; j < bin[i]; j++){
				res[x] = 1;
				x++;
			}
		}
	}

	return 0;
}