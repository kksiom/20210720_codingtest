#include <iostream>
#include <vector>
using namespace std;
#define INF 1000

vector<int> dt(30001, INF);

/*	int fn(int n){
	if (n==1){
		dt[1]=0;
		return dt[1];
	}
	
	if (dt[n] !=INF)
		return dt[n];
		
	
	int count = fn(n-1);
	if ((n%5)==0)
		count = min(count, fn(n/5));
	if ((n%3)==0)
		count = min(count, fn(n/3));
	if ((n%2)==0)
		count = min(count, fn(n/2));
	dt[n]= count +1;
	return dt[n];
	
}*/

int main(){
	int n;
	cin >>n;
	//int count = fn(n);
	
	dt[1]=0;
	for(int i =2; i<=n; i++){
		int count = dt[i-1];
		if ((i%5)==0)
			count = min(count, dt[i/5]);
		if ((i%3)==0)
			count = min(count, dt[i/3]);
		if ((i%2)==0)
			count = min(count, dt[i/2]);
		dt[i]= count +1;
	}
	
	cout << dt[n] << endl;
	return 0;
}