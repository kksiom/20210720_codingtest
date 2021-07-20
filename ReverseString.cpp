#include <iostream>
#include <queue>

using namespace std;
int main() {
	string str;
	cin >> str;
	
	int cntToZero = (str[0] == '1') ? 1 : 0;
	int cntToOne = (str[0] == '0') ? 1 : 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i-1]=='0' && str[i]=='1')
			cntToZero++;
		if (str[i-1]=='1' && str[i]=='0')
			cntToOne++;
	}
	cout << min(cntToZero, cntToOne) << endl;
}