#include <iostream>
#include <string>
using namespace std;

string alfa = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int t;
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	int min_freq = n / k;
    	int resto = n - k*min_freq;
    	int max_min_freq = min_freq + resto;
    	string res = "";
    	for (int i = 0; i < max_min_freq; i++){
    		res += "a";
    	}
    	for (int i = 1; i < k; i++){
    		for (int j = 0; j < min_freq; j++){
    			res += alfa[i];
    		}
    	}
    	cout << res << endl;
    }
    return 0;
}
