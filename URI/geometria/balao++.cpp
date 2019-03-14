#include <cstdio>
#include <iostream>
#define PI 3.1415

using namespace std;

int main (){

    int r, l;
    cin >> r;   
    cin >> l;
    int q = l/((4.0/3)*PI*r*r*r);
    printf("%d\n", q);
    return 0;
}
