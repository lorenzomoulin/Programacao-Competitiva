#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	while(true){
		int n, pos = 0;
		cin >> n;
		if (n == 0)
			break;
		char* nome[n] = {""}, extenso[n] = {""}, res[n] = {""}; 
		bool visited[n] = {false};
		for (int i = 0; i < n; ++i)
		{
			/*string buffer;
			getline(cin, buffer);
			cout << buffer << endl;
			int j = 0;
			for (j = 0; buffer[j] != ' '; j++){
				nome[i] += buffer[j];
			}
			for (j = j + 1; j < buffer.size(); ++j){
				extenso[i] += buffer[j];
			}*/

			scanf("%s", nome[i]);
			scanf("%[^\n]", extenso[i]);
			cout << nome[i] << " " << extenso[i];
				
		}

		for (int i = 0; i < n; ++i)
		{
			int cont = 0;
			for (cont = 0; cont < extenso[i].size();++pos){
				if (pos == n){
					pos = 0;
				}
				if(visited[pos] == false){
					cont++;
					visited[pos] = true;
				}
			}
			res[pos] = nome[i];
		}
		for (int i = 0; i < n - 1; ++i)
		{
			cout << res[i] << " ";
		}
		cout << res[n - 1] << endl;
	}
	return 0;
}