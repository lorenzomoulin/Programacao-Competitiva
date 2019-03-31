#include <bits/stdc++.h>
#define char_num(c) (c >= '0' && c <= '9')
using namespace std;
typedef pair<int, int> ii;

int main(){
	int n;
	scanf("%d", &n);
    ii teste[n];
	for (int i = 0; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		teste[i] = ii(a, b);
	}
	
	int m;
	scanf("%d\n", &m);
	//cout << "M: " << m << endl;
	
	for (int i =0 ; i < m; i++){
		int constantes[20];
		memset(constantes, 0, sizeof(constantes));
		char buffer[1000];
		char sinal = '+';
		int a, b;
		char c;
		while(true){
		    
		    scanf("%c", &c);//printf("%c", c);
		    if(c == ' ')
		        continue;
		    if(c == '='){
		        scanf("%[^\n]\n", buffer);
		        break;
		    }
		    if(char_num(c)){
		        int num_const = c - '0';
		        scanf("%c", &c); //printf("%c", c);
		        if(c == '='){
		            scanf("%[^\n]\n", buffer);
		            if(sinal == '+')
		                constantes[0] += num_const;
		            else
		                constantes[0] -= num_const;
		            break;
		        }
		        if(char_num(c)){
		            num_const = num_const*10 + (c - '0');
		            scanf("%c", &c);//printf("%c", c);
		            if(c == '='){
		                scanf("%[^\n]\n", buffer);
		                if(sinal == '+')
		                    constantes[0] += num_const;
		                else
		                    constantes[0] -= num_const;
		                break;
		            }
		        }
	            //scanf("%c", &c);printf("%c", c);
                if(c == '='){
	                scanf("%[^\n]\n", buffer);
	                break;
	            }
                if(c == 'x' || c == 'X'){
                    scanf("%c", &c);//printf("%c", c);
                    if(c == '='){
		                scanf("%[^\n]\n", buffer);
		                if(sinal == '+')
		                    constantes[1] += num_const;
		                else
		                    constantes[1] -= num_const;
		                break;
		            }
                    if(c == '^'){
                        scanf("%c", &c);//printf("%c", c);
                        if(c == '='){
		                    scanf("%[^\n]\n", buffer);
		                    break;
		                }
                        if(char_num(c)){
                            int num_exp = c - '0';
                            scanf("%c", &c);//printf("%c", c);
                            if(c == '='){
		                        scanf("%[^\n]\n", buffer);
		                        if(sinal == '+')
		                            constantes[num_exp] += num_const;
		                        else
		                            constantes[num_exp] -= num_const;
		                        break;
		                    }
                            if(char_num(c)){
                                num_exp = num_exp*10 + (c - '0');
                                scanf("%c", &c);//printf("%c", c);
                                if(c == '='){
		                            scanf("%[^\n]\n", buffer);
		                            if(sinal == '+')
		                                constantes[num_exp] += num_const;
		                            else
		                                constantes[num_exp] -= num_const;
		                            break;
		                        }
                            }
                            if (sinal == '+')
                                constantes[num_exp] += num_const;        
                            else
                                constantes[num_exp] -= num_const;
                            if(c == '+')
                                sinal = c;
                            else if(sinal == '-')
                                sinal = c;
                        }
                    }
                    else{
                        //printf("SINAL: %c\n\n", sinal);
                        if (sinal == '+')
                            constantes[1] += num_const;        
                        else
                            constantes[1] -= num_const; 
                        if (c == '+')
                            sinal = c;
                        else if(c == '-')
                            sinal = c;
                       
                    }
                }
                else {
                    if (sinal == '+')
                        constantes[0] += num_const;        
                    else
                        constantes[0] -= num_const; 
                    if (c == '+')
                        sinal = c;
                    else if(c == '-')
                        sinal = c;
                }
            }
            else if(c == 'x' || c == 'X'){
                scanf("%c", &c);//printf("%c", c);
                if(c == '='){
	                scanf("%[^\n]\n", buffer);
	                break;
	            }
                if(c == '^'){
                    scanf("%c", &c);//printf("%c", c);
                    if(c == '='){
		                scanf("%[^\n]\n", buffer);
		                break;
		            }
                    if(char_num(c)){
                        int num_exp = c - '0';
                        scanf("%c", &c);//printf("%c", c);
                        if(c == '='){
		                    scanf("%[^\n]\n", buffer);
		                    break;
		                }
                        if(char_num(c)){
                            num_exp = num_exp*10 + (c - '0');
                            scanf("%c", &c);//printf("%c", c);
                        }
                        if (sinal == '+')
                            constantes[num_exp] += 1;        
                        else
                            constantes[num_exp] -= 1;
                        if(c == '+')
                            sinal = c;
                        else if(sinal == '-')
                            sinal = c;
                    }
                }
                else{
                    if (sinal == '+')
                        constantes[1] += 1;        
                    else
                        constantes[1] -= 1; 
                    if (c == '+')
                        sinal = c;
                    else if(c == '-')
                        sinal = c;
                   
                }
            }
            else if(c == '+'){
                sinal = '+';
            }
            else if (c == '-')
                sinal = '-';
            //printf("SINAL: %c\n", sinal);
		}
		
		int flag = 0;
		for (int t = 0; t < n; t++){
			int res = constantes[0];
			for (int k = 1; k < 20; k++){
				if (constantes[k])
					res += constantes[k]*(int)pow(teste[t].first, k);
			}
			if (t == n - 1){
				if (res == teste[t].second){
					if (flag)
						cout << "," << t;
					else{
						cout << t;
						flag++;
					}
				}
			}
			
			else {
				if (res == teste[t].second){
					if (flag)
						cout << "," << t;
					else {
						cout << t;
						flag++;
					}
				}
			}
			
		}
		cout << endl;
	}
	
	return 0;
}
