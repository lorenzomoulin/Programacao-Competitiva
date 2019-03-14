#include <iostream>
#include <cstring>
using namespace std;

//true = Suffix, false = Prefix

 bool prefix(string mp, string a){
 	for (int i = 0; i < a.size(); i++){
 		if (a[i] != mp[i]){
 			return false;
 		}
 	}
 	return true;
 }

 bool suffix(string ms, string a){
 	for (int i = 0; i < a.size(); i++){
 		if (a[a.size() - i - 1] != ms[ms.size() - i - 1]){
 			return false;
 		}
 	}
 	return true;
 }

int busca(int end, string *pre_suf, string x){
	for (int i = 0; i <= end; i++){
		if (!pre_suf[i].compare(x)){
			return i;
		}
	}
	return -1;
}

int main(){
	int n; 
	cin >> n;
	string pre_suf[2*n - 2];
	for (int i = 0; i < 2*n - 2; i++){
		cin >> pre_suf[i];
	}
	string maior_sufix, maior_prefix;
	bool res[2 * n - 2];
	int cont = 0, idx_mp, idx_ms;
	for (int i = 0; 2*n-2; i++){
		if(cont == 0 && pre_suf[i].size() == n - 1){
			maior_prefix = pre_suf[i];
			//cout << maior_prefix << endl;
			idx_mp = i;
			//cout << i << endl;
			res[i] = false;
			cont++;
		}
		else if(cont == 1 && pre_suf[i].size() == n - 1){
			maior_sufix = pre_suf[i];
			//cout << maior_sufix << endl;
			idx_ms = i;
			//cout << i << endl;
			res[i] = true;
			cont++;
			break;
		}
	}
	bool trocar = false;
	for (int i = 0; i < 2 * n - 2; i++){
		if (!pre_suf[i].compare(maior_prefix) || !pre_suf[i].compare(maior_sufix) )
				continue;
		int idx = busca(i - 1, pre_suf, pre_suf[i]);
		if(idx != -1){
			if(res[idx]){
				if(!prefix(maior_prefix, pre_suf[i])){
					//cout << "trocou1\n";
					trocar = true;
					break;
				}
				
			}
			else{
				if(!suffix(maior_sufix, pre_suf[i])){
					//cout << idx << endl;
					//cout << i << endl; 
					//cout << "trocou2\n";
					trocar = true;
					break;
				}
			}
			res[i] = !res[idx];
			continue;
		}
		if (prefix(maior_prefix, pre_suf[i])){
			res[i] = false;
		}
		else if(suffix(maior_sufix, pre_suf[i])){
			res[i] = true;
		}
		else if(!prefix(maior_prefix, pre_suf[i]) && !suffix(maior_sufix, pre_suf[i])){
			//cout << i << endl;
			//cout << "oi\n";
			trocar = true;
			break;
		}
	}
	cont = 0;
	if (trocar){
		for (int i = 0; 2*n-2; i++){
			if(cont == 0 && pre_suf[i].size() == n - 1){
				maior_sufix = pre_suf[i];
				//cout << maior_sufix << endl;
				idx_ms = i;
				//cout << i << endl;
				res[i] = true;
				cont++;
			}
			else if(cont == 1 && pre_suf[i].size() == n - 1){
				maior_prefix = pre_suf[i];
				//cout << maior_prefix << endl;
				idx_mp = i;
				//cout << i << endl;
				res[i] = false;
				cont++;
				break;
			}
		}
		for (int i = 0; i < 2 * n - 2; i++){
			if (!pre_suf[i].compare(maior_prefix) || !pre_suf[i].compare(maior_sufix) )
				continue;
			int idx = busca(i - 1, pre_suf, pre_suf[i]);
			if(idx != -1){
				res[i] = !res[idx];
				continue;
			}
			if (prefix(maior_prefix, pre_suf[i])){
				res[i] = false;
			}
			else if(suffix(maior_sufix, pre_suf[i])){
				res[i] = true;
			}
			else if(!prefix(maior_prefix, pre_suf[i]) && !suffix(maior_sufix, pre_suf[i])){
				trocar = true;
				//cout << "proibido\n";
				break;
			}
		}
	}

	for (int i = 0; i < 2*n - 3; i++){
		if(res[i])
			cout << "S";
		else
			cout << "P";
	}
	if(res[2 * n - 3])
			cout << "S\n";
		else
			cout << "P\n";

	return 0;
}