#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, A, B;

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int atualA, atualB;
		cin >> A >> B;
		atualA = A;
		atualB = B;

		bool complicado = false;
		int n = 1; // expoente

		// se B for 0, então a parte imaginária é 0, portanto
		// já fica sendo um número real e, portanto, o menor expoente é 1,
		// como já iniciamos n = 1, então tudo ok
		if(B != 0)
		{
			// entro em loop infinito para fazer os cálculos
			while(1)
			{
				// (a + bi)*(a + bi)
				// (atualA + atualB*i)*(A + B*i)
				int auxA = atualA;
				atualA = atualA * A - atualB * B;
				atualB = auxA * B + atualB * A;
				n++;
				
				// verifica se é >= a 2^30
				if(atualA >= 1073741824)
				{
					// se for maior, então é muito complicado resolver
					complicado = true;
					break;
				}
				// se atualB (parte imaginária) for 0, então 
				// encontrou o menor "n"
				else if(atualB == 0)
					break;
			}
		}
		
		if(complicado == false)
			cout << n << endl;
		else
			cout << "TOO COMPLICATED\n";
	}
	return 0;
}
