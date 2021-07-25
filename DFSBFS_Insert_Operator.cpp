#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 1e9

int n;
vector<int> arr;//피연산자를 쌓는 벡터
int add, sub, mul, divi;
int minValue=1e9;
int maxValue=-1e9;

//index: arr[]에서 다음번 사용할 피연산자 위치
void dfs(int index, int result, int a, int s, int m, int d)
{
	if (index==n){
		minValue=min(minValue, result);
		maxValue=max(maxValue, result);
		return;
	}
	
	if(a>0)
		dfs(index+1, result+arr[index], a-1,s,m,d);
	if(s>0)
		dfs(index+1, result-arr[index], a,s-1,m,d);
	if(m>0)
		dfs(index+1, result*arr[index], a,s,m-1,d);
	if(d>0)
		dfs(index+1, result/arr[index], a,s,m,d-1);
}


int main(){
	cin >>n;
	for(int i=0;i<n; i++){
		int value;
		cin >> value;
		arr.push_back(value);
	}
	cin>>add>>sub>>mul>>divi;
	
	dfs(1, arr[0], add, sub, mul, divi);
	
	cout << maxValue << endl;
	cout << minValue << endl;
	
	
	
	return 0;
}