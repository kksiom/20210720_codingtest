#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define INF 1e9

int n, l, r;
int arr[50][50];
bool visited[50][50];
int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};

void bfs(vector<pair<int,int>> &pos, int row, int col){
	queue<pair<int,int>> q;
	q.push({row, col});
	pos.push_back({row,col});
	visited[row][col]=true;
	while (!q.empty()){
		row=q.front().first;
		col=q.front().second;
		q.pop();
		
		for (int i=0;i<4;i++){
			int nr = row + dr[i];
			int nc = col + dc[i];
			if (nr<0 || nr>=n || nc<0 || nc>=n)
				continue;
			if (visited[nr][nc]==true)
				continue;
			int diff = abs(arr[row][col] - arr[nr][nc]);
			if(diff<l || diff>r)
				continue;
			
			q.push({nr, nc});
			pos.push_back({nr,nc});
			visited[nr][nc]=true;
		}
	}
}


int main()
{
	cin >>n>>l>>r;
	for(int row=0; row<n;row++){
		for (int col=0; col<n;col++){
			cin>>arr[row][col];
		}
	}
	int count=0;
	while(count <2000){
		memset(visited, 0x00, sizeof(visited));
		bool changed=false;
		for(int row=0; row<n;row++){
			for (int col=0; col<n;col++){
				if (visited[row][col]==0){
					vector<pair<int,int>> pos;
					bfs(pos, row, col);
					
					if(pos.size()==1)
						continue;
					
					changed=true;
					int total=0;
					for(int i=0; i<pos.size();i++){
						int r=pos[i].first;
						int c=pos[i].second;
						total+=arr[r][c];
					}
					int avg=total / pos.size();
					for(int i=0; i<pos.size();i++){
						int r=pos[i].first;
						int c=pos[i].second;
						arr[r][c]=avg;
					}
				}
			}
		}
		if(!changed)
			break;
		count++;
	}
	cout << count <<endl;
	
	
	
	
	return 0;
}