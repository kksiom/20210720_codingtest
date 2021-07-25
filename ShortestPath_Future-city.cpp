#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	int arr[101][101]={0};
	int* ptr = (int*)arr;
	for (int i=0; i<101*101; i++)
		*ptr++= INF;
		
	int n, m ,x, k;
	cin >>n >>m;
	for (int i=1; i<=n; i++)
		arr[i][i]=0;
	for(int i =0; i<m; i++){
		int a,b;
		cin >>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	cin >>x>>k;
	
	for(int mid=1; mid <=n; mid++){
		for (int r =1; r<=n; r++){
			for (int c =1 ; c<=n; c++){
				arr[r][c]=min(arr[r][c], arr[r][mid]+arr[mid][c]);
			}
		}
	}
	int result = arr[1][k] + arr[k][x];
	if (result >= INF)
		result = -1;
	cout << result << endl;
	
	return 0;
}