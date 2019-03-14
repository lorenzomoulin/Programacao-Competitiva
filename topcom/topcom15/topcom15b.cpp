#include <string>
#include <iostream>
#include <vector>

using namespace std;

string passo(string res, int k, int pos){
	string s = res;
	if (s[(pos + k) % s.size()] == 'x')
	{
		s[(pos + k) % s.size()] = 'o';	
	}
	else{
		s[(pos + k) % s.size()] = 'x';
	}
	
	return s;
}

int main(int argc, char const *argv[])
{
	int n, q;
	
	while (true){
		cin >> n >> q;
		if (n == 0 && q == 0)
			break;

		string inicial;
		cin >> inicial;

		for (int i = 0; i < q; ++i)
		{
			int k, m;
			cin >> k >> m;
			vector<string> possiveis;
			int periodo = 0;
			int pos = 0;
			string temp = inicial;
			temp = passo(temp, 0,0);
			possiveis.push_back(inicial);
			
			possiveis.push_back(temp);
			periodo++;
			while(true){
				temp = passo(temp, k, pos);
				pos = (pos + k) % n;
				possiveis.push_back(temp);
				periodo++;
				if (temp.compare(inicial) == 0)
				{
					
					break;
				}
				
			}
			// for (int i = 0; i < possiveis.size(); ++i)
			// {
			// 	cout << possiveis[i] << endl << endl;
			// }
			cout << possiveis[m % (periodo)] << endl; 	
		}
	}
	return 0;
}