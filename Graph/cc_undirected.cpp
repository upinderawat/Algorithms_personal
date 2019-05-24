#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
	int v;
	int e;
	vector<vector<int> >adjList;
	vector<int> visited;
public:
	Graph();
	Graph(int v, int e){
		this->v = v;
		this->e = e;
		adjList.resize(v+1);
		visited.resize(v+1);
		for(auto &v : visited)
			v = -1;
	}
	void addEdge(int u, int v){
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void bfs(int s,int i);
	int connected_components();
};
int Graph::connected_components(){
	int cc=0;
	for(int i=0;i<this->v; i++){
		if(visited[i] == -1){
			bfs(i,cc++);
		}
	}
	return cc;
}
void Graph::bfs(int s, int i){
	queue<int> bfs_queue;
	bfs_queue.push(s);
	while(!bfs_queue.empty()){
		int temp = bfs_queue.front();
		for(auto u : adjList[temp]){
			if(visited[u] == -1){
				bfs_queue.push(u);
			}
		}
		bfs_queue.pop();
		visited[temp] = i;
	} 
}
int main(){
	Graph g(5,3); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4);
    cout<<g.connected_components();
}