#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dt(100, 0);

int fibo(int x){
	int result =0;
	if (dt[x]!=0)
		return dt[x];
	dt[x] = fibo(x-2)+fibo(x-1);

	return dt[x];
}

int main(){
	dt[1] = dt[2]=1;
	int result = fibo(40);
	cout << result <<endl;
	
	return 0;
	
}