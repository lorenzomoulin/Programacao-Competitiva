#include <iostream>
#include <vector>
typedef long long ll;
typedef vector< vector< double > > matrix;

int mod;

matrix operator +(matrix a, matrix b){
    int n = (int)a.size();
    int m = (int)a[0].size();
    matrix c;
    c.resize(n);
    for (int i = 0; i < n; i++){
        c[i].resize(m);
        for (int j = 0; j < m; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    return c;
}

matrix operator *(matrix a, matrix b){
    int n = (int)a.size();
    int m = (int)b.size();
    int p = (int)b[0].size();
    matrix c(n, vector<double>(p));
    vector<double> col(m);
    for (int j = 0; j < p; j++){
        for (int k = 0; k < m; k++)
            col[k] = b[k][j];
        for (int i = 0; i < n; i++){
            double s = 0;
            for (int k = 0; k < m; k++)
                s += a[i][k] * col[k];
            c[i][j] = s;
        }
    }
    return c;
}

matrix operator *(double k, matrix a){
    int n = (int)a.size();
    int m = (int)a[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        a[i][j] *= k;
    return a;
}

matrix operator -(matrix a, matrix b){
    return a + ((-1.0)*b);
}

matrix matrix_exp(matrix a, int n){
    if (n == 0) return id(a.size());
    matrix c = matrix_exp(a, n / 2);
    c = c * c;
    if (n % 2)  c = c * a;
    return c; 
}

matrix fibo(){
    matrix c(2, vector <double>(2, 1));
    c[1][1] = 0;
    return c;
}

double fibo(int n){
    matrix f = matrix_exp(fibo(), n);
    return f[0][1];
}

int main(){
    ios_base::sync_with_stdio(0);
    ll n, m;
    while(cin >> n >> m){
        
    }
    
    return 0;
}
