#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100001
int main()
{
	int start, finish;
	cin >> start >> finish;

	int  trace[MAX];
	for (int i = 0; i < MAX; i++)
		trace[i]=-1;
	
	queue<pair<int, int>>q;
	
	q.push({0, start});
	while (!q.empty())
	{
		int cost = q.front().first;
		int here = q.front().second;
		q.pop();
		if (here == finish){
			ans = cost;
			break;
		}
		if (trace[here*2]==-1 && (here *2<=MAX)){
			q.push({cost +1, here*2});
			trace[here * 2] =here;
		}
		if (trace[here+1]==-1 && (here +1<=MAX)){
			q.push({cost +1, here+1});
			trace[here +1] =here;
		}
		if (trace[here-1]==-1 && (here -1>=0)){
			q.push({cost +1, here-1});
			trace[here -1] =here;
		}
		
	}
	cout << ans;	

	stack<int> st;
	int pos= finish
	st.push(finish);
	while pos != start){
		st.push(trace[pos]);
		pos=trace[pos];
	}
	while (!st.empty()){
		cout <<st.top() <<" ";
		st.pop();
	}
	return 0;
}