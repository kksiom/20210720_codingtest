#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9


int n, m, start;
int graph [101][101];


int main(){
	cin >> n >> m ;
	
	int* ptr = (int*)graph;
	for (int i=0;i<101*101;i++)	
		*ptr++=INF;
	
	for (int i=0;i<101;i++)	
		graph[i][i]=0;
	
	for (int i = 0; i<m; i++){
		int from, to ,cost;
		cin >> from >> to >> cost;
		graph[from][to]= min(graph[from][to], cost);
	}
	
	for (int mid =1; mid<=n; mid++ ){//핵심 for문
		
		for (int from = 1; from <=n; from++){
			for (int to=1; to <=n; to++){
				int newcost = graph[from][mid]+ graph[mid][to];
				if (graph[from][to]>newcost)
					graph[from][to]=newcost;
			}
		}
	}
	
	

	for (int from = 1; from <=n; from++){
		for (int to=1; to <=n; to++){
			if(graph[from][to]==INF)
				cout << "INF "<<" ";
			else
				cout<<graph[from][to]<< " ";
			
		}
		cout <<endl;
	}
	
	
}
