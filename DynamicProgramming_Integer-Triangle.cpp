#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	//위, 위 왼쪽
	int n;
	cin >>n;
	vector<int> *arr= new vector<int>[n];
	int value;
	for (int row=0; row < n; row++){
		for (int col = 0; col <= row; col++){
			cin >> value;
			arr[row].push_back(value);
		}
	}	
	
	for (int row = 1; row < n; row++){
		for (int col = 0; col <=row; col++){
			if (col==0)
				arr[row][col]+= arr[row-1][col];
			else if (col==row)
				arr[row][col]+= arr[row-1][col-1];
			else
				arr[row][col]+= max(arr[row-1][col], arr[row-1][col-1]);
		}
	}
	
	int result = arr[n-1][0];
	for (int col =1; col <n; col++){
		result = max(result, arr[n-1][col]);
	}
	cout<<result<<endl;
	
	return 0;
}