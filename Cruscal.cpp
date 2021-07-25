#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 1e9

int find_parent(vector<int>& parent, int a){
	if (parent[a]!=a)
		parent[a]=find_parent(parent, parent[a]);	
	
	return parent[a];
	
}

void union_parent(vector<int>& parent, int a, int b){
	int pa=find_parent(parent, a);
	int pb=find_parent(parent, b);
	if(pa<pb)
		parent[pb]=pa;
	else
		parent[pa]=pb;
}

void main(){
	int v, e;
	cin >> v >>e;
	
	vector<int> parent;
	for (int i =0; i<=v; i++)
		parent.push_back(i);
	
	//<비용, <from, to>>
	vector<pair<int, pair<int,int>>> edges;
	for (int i =0;i<e;i++){
		int from, to, value;
		cin >>from>>to>>value;
		edges.push_back({value,{from,to}});
	}
	
	sort(edges.begin(), edges.end());
	
	int result =0;
	for(int i =0; i<edges.size();i++){
		pair<int, pair<int, int>> edge=edges[i];
		int cost = edge.first
		int a= edge.second.first;
		int b= edge.second.second;
		
		int pa= find_parent(parent, a);
		int pb= find_parent(parent, b);
		if(pa!=pb){
			union_parent(parent,a,b)
			result+= cost;
			
		}
		
	}
	cout<<result<<endl;
}
