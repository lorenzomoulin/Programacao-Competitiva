#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    while(n--){
        char s[1000];
        char temp = '-';
        
        scanf("\n\"%[^\"]\"", s);

        while(temp != '{')
            scanf("%c", &temp);
        char eval[1000];
        int i;
        int atual = 32001;
        if(scanf(s, &atual) == 1)
            printf("%d", atual);
        while(scanf(s, &atual) == 1){
            printf(" %d", atual);
        }
        scanf(" }");
        if (atual == 32001){
            printf("FALHOU!");
            
        }
        char buffer[10000];
            scanf("%[^\n]\n", buffer);
        cout << endl;
        
    }
    return 0;
}
