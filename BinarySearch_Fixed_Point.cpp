#include <iostream>
#include <vector>

using namespace std;



int main(){
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; i++)
		cin >> arr[i];
	
	int start = 0;
	int end = n-1;
	while (start <=end){
		int mid = (start+end)/2;
		if (mid==arr[mid]){
			cout << mid << endl;
			return 0;
		}
		else if (mid > arr[mid])
			start =mid +1;
		else//if (mid<arr[mid])
			end=mid-1;
	}
	cout << -1 << endl;
	
	
	return 0;
}