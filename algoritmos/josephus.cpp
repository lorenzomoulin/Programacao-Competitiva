#include <bits/stdc++.h>

using namespace std;

int josephus(int n){
	return ((n - (int)(pow(2, (int)log2(n)))) << 1) + 1;
}

int main(){
	for(int i = 1; i < (10000001); i++)
		printf("w(%d): %d\n",i,  josephus(i));
	return 0;
}
