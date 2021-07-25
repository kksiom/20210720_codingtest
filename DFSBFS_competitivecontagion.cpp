#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 1e9

int graph[200][200];
queue<pair<int, pair<int, int>>> q;

int main(){
	
	int n,k,s,x,y;
	cin >>n>>k;
	vector<pair<int, pair<int, int>>> tempvector;
	for(int row=0; row<n;row++){
		for(int col=0; col <n; col++){
			int num;
			cin>>num;
			graph[row][col]=num;
			if(num!=0){
				tempvector.push_back({num,{row,col}});
			}
		}
	}
	cin >>s>>x>>y;
	
	sort(tempvector.begin(), tempvector.end());
	for(int i =0; i < tempvector.size(); i++)
		q.push(tempvector[i]);
	
	int dr[]={0,0,-1,1};
	int dc[]={-1,1,0,0};
	for (int i =0; i<s; i++){
		int count = q.size();
		for (int j=0; j<count; j++){
			int virus=q.front().first;
			int row=q.front().second.first;
			int col=q.front().second.second;
			q.pop();
			
			for(int d=0; d<4; d++){
				int nr = row+ dr[d];
				int nc = col+ dc[d];
				if (nr<0||nr >=n||nc<0||nc>=n)
					continue;
				if (graph[nr][nc]==0){
					graph[nr][nc]=virus;
					q.push({virus, {nr,nc}});
				}
			}
		}
	}
	cout <<graph[x-1][y-1]<<endl;
	return 0;
}