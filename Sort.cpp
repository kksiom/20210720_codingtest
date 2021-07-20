#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	vector<int> a, b;
	cin >> n >> k;
	for (int i =0; i<n; i++){
		int value;
		cin >> value;
		a.push_back(value);
	}
	
	for (int i =0; i<n; i++){
		int value;
		cin >> value;
		b.push_back(value);
	}
	
	sort(a.begin(), a.end());//오름차순
	reverse(b.begin(), b.end());//내림차순
	
	for (int i = 0; i<k; i++){
		if (a[i]<b[i])
		{
			int temp;
			temp=a[i];
			a[i]=b[i];
			b[i]=temp;
		}
		else
			break;
		
	}
	
	int result =0;
	for (int i =0; i<n;i++){
		result +=a[i];
	}
	cout << result << endl;
	
	return 0;
	
}