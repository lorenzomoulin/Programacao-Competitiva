#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    int c = 1;
    int n, p;
    cin >> n >> p;
    while(true){
        if(!n && !p)break;
        scanf("\n");
        FOR(i,  n){
            char buffer[1000];
            scanf("%[^\n]\n", buffer);
        }
        char big_name[1000];
        int big_n = 0;
        float short_price = INF;
        FOR(i, p){
            char name[1000];
            int temp_n;
            float price;
            scanf("%[^\n]\n", name);
            //scanf("\n");
            scanf("%f %d\n", &price, &temp_n);
            //cout << name[0] << " " << price <<  " " << temp_n << endl;
            FOR(j, temp_n){
                char buffer[1000];
                scanf("%[^\n]\n", buffer);
            }
            
            if (temp_n > big_n){
                big_n = temp_n;
                strcpy(big_name, name);//
                short_price = price;
                
            }
            else if (temp_n == big_n){
                if (price < short_price){
                    short_price = price;
                    strcpy(big_name, name);// big_name = name;
                    big_n = temp_n;
                }
            }
            
        }
        cout << "RFP #" << c << endl;
       
        for(int i = 0; big_name[i] != '\0'; i++)
            cout << big_name[i];
        cout << endl;
        c++;
        cin >> n >> p;
        if (!n && !p)break;
        
        else
            cout << endl;
        
    }
    return 0;
}
