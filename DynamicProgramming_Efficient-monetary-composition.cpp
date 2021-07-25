#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	
	vector<int> units;
	int n,m;//화폐종류수, 금액
	cin >>n>>m;
	
	for (int i=0; i<n; i++){
		int value;
		cin >> value;
		units.push_back(value);
	}
	vector<int> dt(m+1, INF);
	dt[0]=0; 
	for (int i =0; i<n; i++){
		for (int j=units[i]; j<=m; j++){
			int prev_count=dt[j-units[i]];
			if (prev_count>=INF)
				continue;
			dt[j]=min(dt[j], prev_count+1);
		}
	}
	
	if (dt[m]>=INF)
		cout << -1 << endl;
	else
		cout << dt[m]<<endl;
	
	
	
	
	
	
	
	
	return 0;
}