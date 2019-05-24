//undirected weighted edges
#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,wt;
	int N;//no of vertices
	int M;//no of edges
	cin>>N;
	cin>>M;
	vector< pair<int,int > > adj[N];
	for(int i=0;i<M;i++){
		cin>>A>>B>>wt;	// A is adjacent to B with weight wt
		adj[A].push_back(make_pair(B,wt));
		adj[B].push_back(make_pair(A,wt));//then B is also adj to A with same wt
		
	}
	cout<<"Adjacency List: \n";
	for(int i=0;i< N;i++){
		cout<<"Node "<<i<<" is connected to: \n";
		for(vector< pair<int,int > >::iterator it = adj[i].begin();it != adj[i].end();it++)
			{
				cout<<"Node "<<it->first<<" Weight: "<<it->second<<"\n";
			}
			cout<<"\n\n";
		}
			
	return 0;
}
