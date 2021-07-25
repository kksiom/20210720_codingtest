#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int arr[8][8];
int temp[8][8];
vector<pair<int, int>> viruspos;//2의 좌표들
vector<pair<int, int>> emptypos;//0의 좌표들
int emptycount=0;

int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};

int result =0;

void virus(int row, int col){
	for (int i=0; i<4; i++){
		int nr = row+dr[i];
		int nc = col+dc[i];
		
		if (nr<0||nr>=n||nc<0||nc>=m)
			continue;
		if (temp[nr][nc]==0){
			temp[nr][nc]=2;
			virus(nr, nc);
		}
	}
}

//temp[][]에 있는 0의 갯수 반환
int getScore(){
	
}

//count: 이미 count 개의 벽을 세웠다.
//emptyindex: emptypos의 [emptyindex] 위치 뒤쪽으로만 벽을 세워라
void dfs(int count, int emptyindex){
	if (count==3){
		for(int r=0; r<n; r++){
			for(int c=0;c<m;c++)
				temp[r][c]=arr[r][c];
		}
		int count = viruspos.size();
		for (int i=0; i<count; i++){
			int row= viruspos[i].first;
			int col= viruspos[i].second;
			virus(row, col);
		}
		result=max(result, getScore());
		return;
	}
	//vector<pair<int,int>>emptypos;//0의 좌표들
	
	for (int i = emptyindex; i<emptycount; i++){
		int row= emptypos[i].first;
		int col= emptypos[i].second;
		
		arr[row][col]=1;
		dfs(count+1, i+1);
		arr[row][col]=0;
	}
}

int main(){
	cin >>n >>m ;
	for (int r=0; r<n; r++){
		for (int c=0;c<m;c++){			
			cin >>arr[r][c];
			if (arr[r][c]==0)
				emptypos.push_back({r,c});
			if (arr[r][c]==2)
				viruspos.push_back({r,c});
		}
	}
	emptycount=emptypos.size();
	
	
	//count: 이미 count 개의 벽을 세웠다.
	//emptyindex: emptypos의 [emptyindex] 위치 뒤쪽으로만 벽을 세워라
	dfs(0, 0);
	
	cout<<result<<endl;
	
	
	
	
	
	
	
	
	
	
	return 0;
}