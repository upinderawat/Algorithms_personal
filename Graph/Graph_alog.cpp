#include <bits/stdc++.h>
using namespace std;

typedef enum color{
	WHITE,//unvisited
	GRAY,//discovered i.e put in queue
	BLACK//processed i.e all immediate childs have been discovered
}color;
class Graph{
private:
	int v;//vertices
	int e;//edges
	vector<vector<int> >adjList;
	vector<color> visited;
public:
	Graph(){};
	Graph(int v, int e){
		this->v = v;
		this->e = e;
		adjList.resize(v+1);
		visited.resize(v+1);
		for(auto i : visited){
			i = WHITE;
		}
	}
	void addEdge(int from, int to){
		adjList[from].push_back(to);
	//	adjList[to].push_back(from); 
	}
	void bfs(int s);
	void dfs(int s);
	void dfs_stack(int s);
	void isCycle(int s,int&);
};
void Graph::isCycle(int s, int &back_edges){
	if(visited[s] == WHITE){
		visited[s] = GRAY;
		for(auto v: adjList[s]){
			if(visited[v] == GRAY){
				back_edges++;
				return;
			}
			if(visited[v] == WHITE){
				isCycle(v,back_edges);
			}
		}
		visited[s] = BLACK;
	}	
}
void Graph::dfs_stack(int s){
	stack<int> aux_stack;
	aux_stack.push(s);
	while(!aux_stack.empty()){
		int temp = aux_stack.top();
		if(visited[temp] == WHITE){
			visited[temp] = GRAY;
			cout<<"Discovered: "<<temp<<"\n";
		}
		for(auto n : adjList[temp]){
			if(visited[n] == WHITE)
				aux_stack.push(n);
		}
		if(temp == aux_stack.top() && visited[temp] == GRAY){
			visited[temp]= BLACK;
			cout<<"Processed: "<<temp<<"\n";
			aux_stack.pop();
		}
	}
}
void Graph::dfs(int s){
	//if tree_edge(u,v) s.t visited[v] == BLACK then presenece of fwd edge/ cross edge
	//if tree_edge(u,v) s.t visited[v] == GRAY then presence of back edge

	if(visited[s] == WHITE){
		visited[s] = GRAY;
		cout<<"Discovered: "<<s<<"\n";
		for(auto v: adjList[s]){
			dfs(v);
		}
		visited[s] = BLACK;
		cout<<"Processed: "<<s<<"\n";
	}

}
void Graph::bfs(int s){// s is the starting vertex
	int temp;
	queue<int> q;
	q.push(s);
	cout<<"Discovered: "<<s<<"\n";
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(auto v : adjList[temp]){
			if(visited[v] == WHITE ){
				visited[v] = GRAY;
				q.push(v);
				cout<<"Discovered :"<<v<<"\n";
			}
		}
		visited[temp] = BLACK;
		cout<<"Processed :"<<temp<<"\n";
		
	}
}
int main(){
	// Graph g(6,8);
	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(2,3);
	// g.addEdge(2,4);
	// g.addEdge(3,4);
	// g.addEdge(4,5);
	// g.addEdge(4,6);
	// g.addEdge(5,6);
	// g.bfs(1);
	// g.dfs(1);
	//g.dfs_stack(1);

	int T;
	int vertices,edges;
	int u,v;
	cin>>T;
	while(T--){
		cin>>vertices>>edges;
		Graph *g = new Graph(vertices,edges);
		while(edges--){
			cin>>u>>v;
			g->addEdge(u, v);
		}
		int back_edges=0;
		g->isCycle(u,back_edges);
	//	cout<<back_edges<<"\n";
		back_edges>0?cout<<"1\n":cout<<"0\n";
		delete g;
	}
	return 0;
}
