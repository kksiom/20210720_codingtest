#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int main(){
	
	int mats;
	vector<int> result;
	cin >> mats;
	for( int mat = 0; mat < mats; mat++){
		int rows, cols;
		cin >> rows >> cols;
		int gold[20][20];
		for (int r=0; r<rows; r++){
			for (int c=0; c<cols; c++){
				cin >> gold[r][c];
			}
		}
		
		for (int col = 1; col < cols; col++){
			for (int row = 0; row < rows; row++){
				int maxvalue=gold[row][col-1];
				if ((row-1)>=0)
					maxvalue=max(maxvalue, gold[row-1][col-1]);
				if ((row+1)< rows)
					maxvalue=max(maxvalue, gold[row+1][col-1]);
				gold[row][col]+= maxvalue;
				
			}
		}
		int maxgold =0;
		for (int row=0; row < rows; row++)
			maxgold=max(maxgold, gold[row][cols-1]);
		//result에 숫자 추가
		result.push_back(maxgold);
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] <<endl;
	
	
	
	return 0;
}