#include <iostream>
#include <vector>
#include <string>
#define push_back pb
using namespace std;

struct vec{
    string nome;
    int B, Cd, D;
    int L[11], U[11], C[11];
};

int add(vec A, int *ii){
    int a = A.C[0];
    for (int i = 1; i <= D; i++){
    	a += A.C[i] * ii[i];
    }
    return a;
}

int main(){
	int N, R;
	cin >> N >> R;
	vec A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i].nome >> A[i].B >> A[i].Cd >> A[i].D;
		for (int j = 0; j < A[i].D; j++){
			cin >> A[i].
		}
		for (int j = 0; j < A[i].D; j++){
			int t;
			cin >> t; 
			A[i].U.pb(t);
		}

	}
	while(R--){

	}
    return 0;
}
