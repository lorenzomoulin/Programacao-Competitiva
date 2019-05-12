#include <bits/stdc++.h>

using namespace std;



string X,Y; 
  
// Returns length of function for longest common   
// substring of X[0..m-1] and Y[0..n-1]  
int lcs(int i, int j, int count)  
{ 
      
    if (i == 0 || j == 0) 
        return count; 
          
    if (X[i-1] == Y[j-1]) { 
        count = lcs(i - 1, j - 1, count + 1); 
    } 
        count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0))); 
    return count; 
} 

int main(){
    while(true){
        string t;
        getline(cin, X);
        //int n = t.size(), m;
        cout << X << '\n'; 
        if (!X.compare(""))    break;
        //for(int i = 0; i < t.size(); i++)
          //  s1[i + 1] = t[i];
        getline(cin, Y);
        //m = t.size();
        //for(int i = 0; i < t.size(); i++)
          //  s2[i + 1] = t[i];
        cout << Y << '\n';
        //memset(tab, -1, sizeof tab);
        cout << lcs((int)X.size(), (int)Y.size(), 0) << '\n';
        X = "";
        Y = "";
    }
    return 0;
}
