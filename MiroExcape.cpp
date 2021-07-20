#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int graph[1000][1000];

void bfs(int r, int c){
	queue<pair<int, int>> q;
	int dr[]={0,0,-1,1};
	int dc[]={-1,1,0,0};
	
	q.push({r, c});
	graph[r][c]=1;
	while (!q.empty()){
		r=q.front().first;
		c=q.front().second;
		q.pop();
	
	
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc>=m)
				continue;
			if(graph[nr][nc]!=1)
				continue;
		
			q.push({nr, nc});
			graph[nr][nc]=graph[r][c]+1;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int r = 0; r < n; r++) {
		for (int c=0; c<m; c++){
			scanf("%1d", &graph[r][c]);
		}
	}
	
	bfs(0, 0);
	
	return 0;
}