#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	int arr[501][501]={0};
	int* ptr = (int*)arr;
	for (int i=0; i<101*101; i++)
		*ptr++= INF;
		
	int n, m ;
	cin >>n >>m;
	for (int i=1; i<=n; i++)
		arr[i][i]=0;
	for(int i =0; i<m; i++){
		int a,b;
		cin >>a>>b;
		arr[a][b]=1;
	}

	
	for(int mid=1; mid <=n; mid++){
		for (int r =1; r<=n; r++){
			for (int c =1 ; c<=n; c++){
				arr[r][c]=min(arr[r][c], arr[r][mid]+arr[mid][c]);
			}
		}
	}
	int result = 0;
	for (int i =1; i <=n ;i++ ){
		// [i] 학생과 관계가 명확한 학생의 수를 센다.
		int count = 0;
		for (int j = 1; j<=n; j++){
			if (arr[i][j]<INF || arr[j][i]<INF)
				count++;
		}
		if (count ==n)
			result++;
	}
	cout << result << endl;
	return 0;
}