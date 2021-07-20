#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int lowerBound(vector<int> arr, int target) {
	int begin = 0;
	int end = arr.size();//-1
	int mid; //= (begin + end) /2;
	while (begin < end){
		mid = (begin + end)/2;
		if (arr[mid] <target){
			begin=mid+1;
		}
		else if(arr[mid] ==target){
			end=mid;
		}
		else if(arr[mid] > target){
			end=mid;
		}
	}
	return begin;
}

int upperBound(vector<int> arr, int target) {
	
	int begin = 0;
	int end = arr.size();//-1
	int mid; //= (begin + end) /2;
	while (begin < end){
		mid = (begin + end)/2;
		if (arr[mid] <target){
			begin=mid+1;
		}
		else if(arr[mid] ==target){
			begin=mid+1;7 
		}
		else if(arr[mid] > target){
			end=mid;
		}
	}
	return begin;
}


int main(){
	int m, n;
	cin >> n >> m;
	
	for(int i = 0; i <n; i++){
		int value;
		cin >>value;
		arr.push_back(value);
	}
	int i1 = lowerBound(arr,x);
	int i2 = upperBound(arr,x);
	if ((i1>=arr.size()||(arr[i1]!=x))
		cout << -1 <<endl;
	else
		cout << (i2-i1) << endl;
	
	return 0;
	
}