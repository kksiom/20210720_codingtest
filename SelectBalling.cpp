#inclutde <iostream>
#include <vector>
using namespace std;

int main(){
	int m, n;
	cin >> n >> m;
	
	vector<int> arr(m+1);
	for (int i = 0; i < n; i++){
		int index;
		cin >> index;
		arr[index]++;
	}
	
	int result = 0;
	for (int i=1; i<=m; i++){
		result += arr[i]*(n-arr[i]);
	}
	result /=2;
	cout << reuslt <<endl;
	
	return 0;
	
}