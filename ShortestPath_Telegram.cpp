#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	int n, m, start;
	cin >> n >> m>> start;
	vector<pair<int,int>>* graph=new vector<pair<int,int>>[n+1];
	for (int i=0; i<m; i++){
		int from, to, value;
		cin>>from>>to>>value;
		graph[from].push_back({to, valeu});
	}
	vector<int> dt(n+1, INF);
	
	//다익스트라
	priority_queue<pair<int, int>> pq; //(-비용, 상대노드)
	dt[start]=0;
	pq.push({-0, start});
	while (!pq.empty()){
		int cost = -pq.top().first;
		int now=pq.top().second;
		pq.pop();
		
		if (dt[now]<cost)
			continue;
		
		for (int i=0; i < graph[now].size(); i++){
			int to = graph[now][i].first;
			int nextcost=graph[now][i].second+dt[now];
			if(dt[to]>nextcost){
				dt[to]=nextcost;
				pq.push({-nextcost, to});
			}
		}
		
	}
	int count = 0;
	int maxdist = 0;
	for(int i=1; i<=n; i++){
		if(i!=start && dt[i]<INF){
			count++;
			maxdist=max(maxdist, dt[i]);
		}
	}
	
	cout << count << " "<< maxdist<< " "<< endl;
	
	return 0;
}