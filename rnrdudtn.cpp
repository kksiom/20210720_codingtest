#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GradeInfo{
public:
	string name;
	int kor, eng, math;
		
	GradeInfo(string _n, int _k, int _e, int _m){
		name = _n;
		kor = _k;
		eng = _e;
		math = _m;
	}
	bool operator<(const GradeInfo &d2){
		if (this->kor == d2.kor){
			if (this->eng == d2.eng){
				if (this->math == d2.math){
					return (this->name < d2.name);
				}
				else
					return (this->name > 2.name);
			}
			else
				return (this->eng < d2.eng);
		}	
		else
			return (this->kor > d2.kor);
	}
}

int main(){
	int n;
	cin >> n;
	vector<GradeInfo> info;
	for (int i=0; i<n;i++){
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		GradeInfo data(name, k, e, m);
		info.push_back(data);
		
	}
	sort( infor.begin(), data.end());
	
	for (int i = 0; i < infor.size(); i++){
		cout << info[i].name << "\n";
	}
	
	
	return 0;
	
}