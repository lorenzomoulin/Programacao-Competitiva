#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


int h, v, m, n, maior_x = 0, maior_y = 0, qtd_zumbis_maior = 0, qtd_nao_zumbis_maior = 0, qtd_zumbis = 0, qtd_nao_zumbis = 0;
string mapa[1000];

bool validPosition(int x, int y){
	return (x >= 0 && x < m && y >= 0 && y < n);
}

void brute(){
	//para cada posicao no mapa, contar quantos zumbis
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = 0; j < m; ++j)
		{
			bool ultrapassa = false;
			qtd_zumbis = 0;
			qtd_nao_zumbis = 0;

			for(int a = i - v; a <= i + v; a++){
				for(int b = j - h ; b <= j + h; b++){
					
					if (validPosition(b, a)){
						
						if(mapa[a][b] == '1')
							qtd_zumbis++;
						else if (mapa[a][b] == '2')
							qtd_nao_zumbis++;
					}
					else {
						ultrapassa = true;
						break;
					}
				}
				if(ultrapassa)
					break;
			}
			if (ultrapassa)
			{
				continue;
			}
			//cout << "MELHOR POSICAO: (" << maior_x << ", " << maior_y << ") ZUMBIS: " << qtd_zumbis_maior << " NAO_ZUMBIS: " << qtd_nao_zumbis_maior << ") POSICAO DE DETONACAO: (" << j << ", " << i << ") ZUMBIS: " << qtd_zumbis << " NAO_ZUMBIS: " << qtd_nao_zumbis << endl;
			if (qtd_zumbis > qtd_zumbis_maior){
				maior_y = i;
				maior_x = j;
				qtd_zumbis_maior = qtd_zumbis;
				qtd_nao_zumbis_maior = qtd_nao_zumbis;
			}
			else if (qtd_zumbis == qtd_zumbis_maior){
				if (qtd_nao_zumbis < qtd_nao_zumbis_maior){
					maior_y = i;
					maior_x = j;
					qtd_zumbis_maior = qtd_zumbis;
					qtd_nao_zumbis_maior = qtd_nao_zumbis;
				}
				else if(qtd_nao_zumbis_maior == qtd_nao_zumbis){
					if(i < maior_y){
						maior_y = i;
						maior_x = j;
						qtd_zumbis_maior = qtd_zumbis;
						qtd_nao_zumbis_maior = qtd_nao_zumbis;
					}
					else if (i == maior_y){
						if (j < maior_x){
							maior_y = i;
							maior_x = j;
							qtd_zumbis_maior = qtd_zumbis;
							qtd_nao_zumbis_maior = qtd_nao_zumbis;
						}
					}
				}
			}
		}
	}
	//
}

int main(){
	int u;
	cin >> u;
	while(u--){
		cin >> h >> v >> m >> n;
		maior_x = maior_y = qtd_nao_zumbis_maior = qtd_zumbis_maior = 0;
		for(int i = 0; i < n; i++){
			cin >> mapa[i];
		}
		brute();
		cout << "X:" << maior_x << " Y:" << maior_y << endl;
	}
	return 0;
}