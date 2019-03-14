#include <iostream>

using namespace std;

int main(){
    float table[5] = {4, 4.5, 5, 2, 1.5};
    int cod, q;
    cin >> cod >> q;
    printf("Total: R$ %.2f\n", table[cod-1]*q);
    return 0;
}
