#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9


int n, m, start;
vector<pair<int, int>>* graph;
vector<int> visited;
vector<int> dist;

int get_smallest_node(){
	int min_value=INF;
	int index=0;
	for(int i = 1; i<=n;i++){
		if (visited[i]==0 && dist[i]< min_value){
			min_value=dist[i];
			index=i;
		}
	}
	return index;
}

void dijkstra(int start){
	dist[start]=0;
	for(int i = 0; i<n;i++){
		int from = get_smallest_node();
		visited[from]=1;
		for(int k=0; k<graph[from].size();k++){
			pair<int, int> j=graph[from][k];
			int to = j.first;
			int cost = j.second;
			if ((dist[from]+cost)<dist[to]){
				dist[to]=dist[from]+cost;
			}
		}
	}
}


int main(){
	cin >> n >> m >>start;
	graph = new vector<pair<int,int>>[n+1];
	for (int i = 0; i<m; i++){
		int from, to ,cost;
		cin >> from >> to >> cost;
		graph[from].push_back({to,cost});
	}
	for (int i = 0;i<=n;i++){
		visited.push_back(0);
		dist.push_back(INF);
	}
	
	dijkstra(start);
	
	for (int i = 1; i<=n;i++){
		if (dist[i]==INF)
			cout << "INF ";
		else
			cout <<dist[i]<<" ";
	}
	return 0;
}
