#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(true){
        int a[10] = {1,2,3,4,5,0,6,7,8,9};
        if(!N)
            break;
        bool um = false;
        
        do{
            int num = a[4] + 10*a[3] + 100*a[2] + 1000*a[1] + 10000*a[0];
            int den = a[9] + 10*a[8] + 100*a[7] + 1000*a[6] + 10000*a[5];
            if (num % den == 0 && num / den == N)
                printf("%05d / %05d = %d\n", num, den, N), um = true;
        }while(next_permutation(a, a + 10));
        /*for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
            int abcde = fghij * N; // this way, abcde and fghij are at most 5 digits
            int tmp, used = (fghij < 10000); // if digit f=0, then we have to flag it
            tmp = abcde; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            tmp = fghij; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            if (used == (1<<10) - 1)
                // if all digits are used, print it
                printf("%05d / %05d = %d\n", abcde, fghij, N), um = true;
        }*/
        if(!um)
            printf("There are no solutions for %d.\n", N);
        cin >> N;
        if(!N)
            break;
        else
            printf("\n");
    }
    return 0;
}
