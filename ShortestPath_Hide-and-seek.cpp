#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	int n, m;
	cin>>n>>m;
	vector<int> *graph = new vector<int>[n+1];
	for (int i=0; i<m; i++){
		int a,b;
		cin >>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	vector<int> dt(n+1, INF);
	priority_queue<pair<int, int>> pq; // <-비용, 노드>
	dt[1]=0;
	pq.push({-0,1});
	while (!pq.empty()){
		int cost = -pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		
		if(dt[cur]< cost)
			continue;
		for (int i=0; i < graph[cur].size();i++){
			int to=graph[cur][i];
			int newcost=cost+1;
			if (dt[to]>newcost){
				dt[to]=newcost;
				pq.push({-newcost,to});
			}
		}
		
	}
	
	//가장 큰 최단거리
	int maxdist=0;
	//가장 최단거리가 긴 노드
	int dest=2;
	//가장 최단거리가 긴 노드들의 갯수
	int maxs=0;
	for (int i =2; i <=n; i++ ){
		if(dt[i]>=INF)
			continue;
		if (dt[i]>maxdist){
			maxdist=dt[i];
			dest=i;
			maxs=1;
		}
		else if (dt[i]==maxdist){
			maxs++;
		}
	}
	
	cout << dest << maxdist << maxs<<endl;
	return 0;
}