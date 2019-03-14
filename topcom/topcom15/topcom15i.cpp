#include <iostream>
#include <string>

using namespace std;



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int ordem, qnt_regras;
		string inicial;
		string regras[256];
		for (int i = 0; i < 256; ++i)
		{
			regras[i] = "";
		}
		cin >> ordem >> inicial >> qnt_regras;
		for (int i = 0; i < qnt_regras; ++i)
		{
			string regra;
			//cout << "OK\n";
			cin >> regra;
			//cout << endl << regra.capacity() << endl;

			regras[regra[0]].assign(regra.substr(2));

		}

				//cout << "\nOK\n";
		for (int i = 0; i < ordem; ++i)
		{
			string temp = "";
			int n = inicial.size();
			for (int j = 0; j < n; j++)
			{
				if(regras[inicial[j]].compare("") != 0){
					temp += regras[inicial[j]];
				}
				else
					temp += inicial[j];
			}
			inicial = temp;
		}
		cout << inicial << endl;
	}
	return 0;
}