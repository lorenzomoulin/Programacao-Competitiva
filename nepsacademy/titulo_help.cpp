#include <iostream>

using namespace std;

string title(string F)
{
    for (int i=0; i<F.size(); i++)
    {
        if ((i==0 or F[i-1]==' ') and (F[i]>='a' and F[i]<='z'))
            F[i]+='A'-'a';
        else if ((i!=0 or F[i-1]!=' ') and (F[i]>='A' and F[i]<='Z'))
            F[i]-='A'-'a';

    }
    return F;
}

int main(){
    string F;

    getline(cin, F);

    cout << title(F) << "\n";
}
