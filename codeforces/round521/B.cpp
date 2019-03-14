#include <iostream>

using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n];
    bool dis[n];
    bool l[n];
    int sum = 0;
    for (int i = 0; i < n; i++){
        dis[i] = false;
        cin >> a[i];
        
    }
    for (int i = 1; i < n-1; i++){
        if (i > 0 && i < n-1){
            if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1){
                dis[i] = true;
            }
        }
    }  
    //for (int i = 0 ; i < n; i++)    cout << dis[i] << " ";
    //cout << endl;
    for (int i = 1; i < n-1; i++){
        if (dis[i]){
            if (i > 1){
                if (!dis[i - 2]){
                    //cout << i << " ";
                    dis[i] = false;
                    if (i < n-2){
                        dis[i + 2] = false;
                        
                    }
                    l[i + 1] = true;
                    sum++;
                }
            }
            else {
                //cout << i << " ";
                l[i + 1] = true;
                dis[i + 2] = false;
                dis[i] = false;
                sum++;
            }
        }
    } 
    //for (int i = 0 ; i < n; i++)    cout << dis[i] << " ";
    //cout << endl;
    cout << endl << sum << endl;
    return 0;
}
