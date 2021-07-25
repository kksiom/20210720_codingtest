#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	
	int n;
	cin >>n;
	int arr[100]; //[i]번째 창고의 식량의 양
	int dt[100]={0};  // [i]번째 까지 최대로 얻을 수 있는 식량의 양
	for (int i =0; i<n; i++){
		cin >> arr[i];
	}
	
	dt[0]=arr[0];
	dt[1]=max(arr[0], arr[1]);
	for (int i=2; i<n; i++){
		dt[i]=max(dt[i-1], dt[i-2]+arr[i]);
		
	}
	int result = max(dt[n-2], dt[n-1]);
	cout << result << endl;
	
	return 0;
}