#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 1e9

int n;
char arr[6][6];
vector<pair<int,int>> teacher;

bool watch(int row, int col){
	//up
	for (int r=row-1; r>=0; r--){
		if(arr[r][col]=='O')
			break;
		if(arr[r][col]=='S')
			return true;
	}
	//down
	for (int r=row+1; r<n; r++){
		if(arr[r][col]=='O')
			break;
		if(arr[r][col]=='S')
			return true;
	}
	//left
	for (int c=col-1; c>=0; c--){
		if(arr[row][c]=='O')
			break;
		if(arr[row][c]=='S')
			return true;
	}
	//right
	for (int c=col+1; c<n; c++){
		if(arr[row][c]=='O')
			break;
		if(arr[row][c]=='S')
			return true;
	}
	return false;
}

//보이는 학생이 있을 때 true
//보이는 학생이 없을 때 false
bool dfs(int walls)
{
	if(walls==3){
		for (int i=0;i<teacher.size(); i++){
			int row = teacher[i].first;
			int col = teacher[i].second;
			if (watch(row, col))
				return true;
		}
		return false;
	}
	
	for(int row=0; row <n; row++){
		for (int col=0; col < n; col++){
			if (arr[row][col]=='X'){
				arr[row][col]='O';
				if(dfs(walls+1)==false)
					return false;
				arr[row][col]='X';
			}
			
		}
	}
	return true; //다른점
}
	
int main()
{
	cin >>n;
	for(int row=0; row <n; row++){
		for (int col=0; col <  n; col++){
			cin >>arr[row][col];
			if (arr[row][col]=='T')
				teacher.push_back({row, col});
			
		}
	}
	
	bool watch = dfs(0);
	cout <<(watch ? "NO" : "YES")<<endl;	
	
	return 0;
}