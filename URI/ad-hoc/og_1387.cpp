#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        short a, b;

        scanf("%hu %hu", &a, &b);
        if (!(a or b))
            break;
        printf("%hu\n", (a + b));
    }
    return 0;
}

