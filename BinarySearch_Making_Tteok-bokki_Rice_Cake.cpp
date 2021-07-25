#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



int main(){
	int n, m;//떡의 갯수, 요청한 떡의 길이
	vector<int> arr;
	cin>>n>>m;
	int start = 0, end = 0;
	
	for (int i = 0; i<n; i++){
		int value;
		cin >> value;
		end = max(end, value);
		arr.push_back(value);
	}
	
	int result = 0;
	while (start <= end ){
		int mid = (start+end)/2;
		
		//OK? NG?
		long long total = 0;
		for (int i=0;i<n;i++){
			if(arr[i]>mid)
				total+=arr[i]-mid;
		}
		if (total>=m){//OK
			result = mid;
			start=mid+1;
		}
		else
			end=mid-1;
	}
	
	cout<<result<<endl;
	
	
	return 0;
}