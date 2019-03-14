#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int c2n(char c)
{
    return c - '0';
}

bool isNum(char c)
{
    return (c>='0') && (c<='9');
}

int main(){
    
    string line;
    while(getline (cin,line))
    {
        string resp;
        int i=0;
        int tam = line.size();
        const char* c_line = line.c_str();
        for(;i<tam-2;)
        {
            if(c_line[i]=='(')
            {
                resp+=c_line[i+1];
                i+=3;
                continue;
            }
            
            if( isNum(c_line[i]) && isNum(c_line[i+1]) && isNum(c_line[i+2]) )
            {
                int ascii_num = (c2n(c_line[i])*100) + (c2n(c_line[i+1])*10) + (c2n(c_line[i+2])*1);
                char try_char = (char)ascii_num;
                if( (try_char=='(') || (try_char==')') || (try_char>='a' && try_char<='z') || (try_char>='A' && try_char<='Z') )
                {
                    // cout << "DEBUG: " << try_char << endl;
                    resp+=try_char;
                    i+=3;
                    continue;
                }
            }
            
            resp+=c_line[i];
            i++;
        }
        
        for(;i<tam;i++)
        {
            resp+=c_line[i];
        }
        
        cout << resp << endl;
    }

    //cout << endl;
    
    return 0;
}