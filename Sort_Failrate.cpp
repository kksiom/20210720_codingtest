#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



int main(){
	int n, m;
	cin>>n>>m;
	
	int *stages= new int[n+2];//[0]->[n+1]
	memset(stages, 0x00, sizeof(int)*(n+2));
	for(int i=0; i<m; i++){
		int num;
		cin >>num;
		stages[num]++;
		
	}
	
	vector<pair<float, int>> failrate; //<-실패율, 스테이지 번호> 내림차순위한 -값
	int total = m;
	for (int i = 1; i <=n; i++){
		failrate.push_back({-stages[i]/(float)total, i});
		total -= stages[i];
	}
	
	sort(failrate.begin(), failrate.end());// 실패율 내림차순-> 스테이지 번호 오름차순
	
	for(int i=0; i<n; i++)
		cout << failrate[i].second << " ";
	cout << endl;
	
	
	return 0;
}