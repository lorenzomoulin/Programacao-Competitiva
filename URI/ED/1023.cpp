#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include<cmath>

using namespace std;

struct imovel{int x; int y;};

bool compara(imovel a, imovel b){ return (a.y/a.x < b.y/b.x);}

int main(){
    
    int count = 0;
    while (true){
        int N;
        count++;
        cin >> N;
        if (!N) break;
        vector<imovel> i;
        for (int j = 0; j < N; j++){
            int x,y;
            cin >> x >> y;
            imovel a; a.x = x; a.y = y;
            i.push_back(a);
        }
        sort(i.begin(), i.end(), compara);
        cout << "Cidade# " << count << ":\n";
        int np, nc;np=nc=0;
        for (int j = 0; j < N - 1; j++){
            int x = i[j].x, y = i[j].y;
            np += x; nc += y;
            int xd = (int)y/(int)x;
            cout << x << "-" << xd << " ";
        }
        np += i[N-1].x; nc += i[N-1].y;
        cout << i[N-1].x << "-" << i[N-1].y/i[N-1].x << endl;
        
        cout << "Consumo medio: "; //<< ("%.2f",1.00*nc/(1.00*np)) << " m3\n";
        printf("%.2f m3.\n",trunc(100*nc/(1.0*np))/100.0);
    }

    return 0;
}
