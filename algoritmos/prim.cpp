#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
typedef long long ll;
typedef pair<int ,int > ii;

vector<pair<int, int>> input;
vector<pair<int, int>> grafo[10000];

double prim(){
    bool taken[MAXN];
    memset(taken, false, sizeof taken);
    taken[0] = true;
    priority_queue<ii> pq;
    ii v, front; int u, w; ll cost = 0;
    for(int j = 0; j  <(int )grafo[0].size(); j++){
        v = grafo[0][j];
        pq.push(ii(-v.second, -v.first));
    }
    while(!pq.empty()){
        front = pq.top(); pq.pop();
        u = -front.second; w = -front.first;
        if (!taken[u]){
            cost += (ll)w; taken[u] = true;
            for(int j = 0; j < (int)grafo[u].size(); j++){
                v = grafo[u][j];
                if(!taken[v.first])
                    pq.push(ii(-v.second, -v.first));
            }
        }
    }
    return cost;
}

int main(){
    
    
    int x, y;
    while (scanf("(%d,%d)\n", &x, &y) == 2){
        printf("%d, %d\n", x, y);
        input.push_back(pair<int, int>(x, y));
    }
    
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < i; j++){
            grafo[i].push_back(ii(hypot(input[j].first - input[i].first,input[j].second - input[i].second ), j));
        }
        for(int j = i + 1; j < input.size(); j++)
            grafo[i].push_back(ii(hypot(input[j].first - input[i].first,input[j].second - input[i].second ), j));
    }
    printf("%lld\n", prim());
    return 0;
}
