#include <iostream>
using namespace std;

int main(){
    long long int A,B,C,D;

    cin>>A>>B>>C>>D;

    for(long long int i=A, j=2;j*i<=1000000000;j++){
        if(((j*i)%A==0)&&((j*i)%B>0)&&(C%(j*i)==0)&&((D%(j*i)!=0)||D<(j*i))){
            cout<<j*i<<"\n";
            return 0;
        }
    }

    cout<<-1<<"\n";


    return 0;
}
