#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9



int main(){
	int n, m , k ,x ;//노드수, 간선수, 원하는 최단거리, 출발도시
	cin>>n>>m>>k>>x;
	vector<int> *graph=new vector<int>[n+1];
	for (int i =0; i<m;i++){
		int from, to;
		cin>>from>>to;
		graph[from].push_back(to);
	}
	vector<int> visited(n+1, -1);
	
	queue<int> q;
	
	q.push(x);
	visited[x]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		
		if(visited[cur]>=k)
			continue;
		for (int i =0; i<graph[cur].size();i++){
			int to = graph[cur][i];
			if(visited[to]!=-1){
				q.push(to);
				visited[to]= visited[cur]+1;
			}
		}
	}
	bool found =false;
	for(int i=1;i<=n;n++){
		if (visited[i]==k){
			cout << i <<endl;
			found=true;
		}
	}
	if(!found)
		cout << -1 <<endl;
	return 0;
}