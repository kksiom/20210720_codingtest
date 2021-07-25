#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, c;
vector<int> arr;

bool IsOK(int dist){
	int cur=0; //1번째 공유기가 있는 집의 index.
	for (int i=1; i<c; i++){
		int curdist=0;
		while ((cur < (n-1)) && (curdist<dist)){
			int next=cur +1;
			curdist += arr[next]-arr[cur];
			cur = next;
		}
		if (curdist<dist)
			return false;
	}
	
	return true;
}

int main(){
	cin >> n >>c;
	for (int i = 0; i<n; i++){
		int value;
		cin >> value;
		arr.push_back(value);
	}
	
	sort(arr.begin(), arr.end());
	
	int mindist=1;
	int start=1;
	int end=arr[n-1]-arr[0];
	
	while(start<=end){
		int mid =(start+end)/2;
		
		if(IsOK(mid)){
			mindist = mid;
			start = mid+1;
		}
		else {
			end =mid-1;
		}
	}
	cout<<mindist<<endl;
	
	
	return 0;
}