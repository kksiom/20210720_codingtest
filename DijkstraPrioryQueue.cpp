#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9


int n, m, start;
vector<pair<int, int>>* graph;
vector<int> dist;
priority_queue<pair<int,int>> pq;


void dijkstra(int start){
	pq.push({-0, start});//<-비용, 상대노드>
	dist[start]=0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now]<cost)
			continue;
		
		
		for(int k=0; k<graph[now].size();k++){
			pair<int, int> j=graph[now][k];
			int to = j.first;
			int cost = j.second;
			if ((dist[now]+cost)<dist[to]){
				dist[to]=dist[now]+cost;
				pq.push({-dist[to], to});
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
