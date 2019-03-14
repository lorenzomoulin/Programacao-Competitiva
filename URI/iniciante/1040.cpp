#include <iostream>

using namespace std;

int main(){
    int ai, ad, bi, bd, ci, cd, di, dd;
    scanf("%d.%d %d.%d %d.%d %d.%d", &ai,&ad, &bi, &bd, &ci, &cd, &di, &dd); 
    float media = 2.0*ai + 3.0*bi + 4.0*ci + 1.0*di + 0.2*ad + 0.3*bd + 0.4*cd + 0.1*dd;
    media /= 10.0;
    printf("Media: %.1f\n", media);
    if (media >= 7.000000){cout << "Aluno aprovado.\n";}
    else if (media < 5.000000) {cout << "Aluno reprovado.\n";}
    else if (media >= 5.00000 && media <= 6.9000000){
        cout << "Aluno em exame.\n";
        
        float n;
        cin >> n;
        media += n;
        media /= 2;
        printf("Nota do exame: %.1f\n", n);
        if (media >= 5.000000) cout << "Aluno aprovado.\n";
        else    cout << "Aluno reprovado.\n";
        printf("Media final: %.1f\n", media); 
    }
    return 0;
}
