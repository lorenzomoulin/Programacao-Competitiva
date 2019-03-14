#include <pair>
#include <vector>
#include <iostream>

using namespace std;

#define VISITED 1
#define UNVISITED -1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vi dfs_num;

void dfs(int u){
	dfs_num[u] = VISITED;
	for (int i = 0; i < (int)AdjList[u].size(); ++i)
	{
		ii v = AdjList[u][i];
		if(dfs_num[v.first] == UNVISITED)
			dfs(v.first);
	}
}

int main(int argc, char const *argv[])
{
	//Finding connected components in undirected graph

	return 0;
}