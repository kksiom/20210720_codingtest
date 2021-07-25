#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	
	int n;
	cin >>n;
	
	int dt[1000];
	dt[0]=1;
	dt[1]=3;
	for(int i=2; i<n; i++)
		dt[i]=dt[i-1]+dt[i-2]*2;
	
	cout << (dt[n-1] % 796796) <<endl;
	
	
	
	
	
	
	return 0;
}