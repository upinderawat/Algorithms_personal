#include <iostream>
#include <stack>
#include <list>

using namespace std;
class Graph{
	int V;
	list<int > *adjList;
	bool *visited;
public:
	Graph(int V){
		int i;
		this->V = V;
		adjList = new list<int >[V];
		visited = new bool[V];
		for(i=0;i<V;i++)
			visited[i] = false;
	}
	void addEdge(int, int);
	void DFS(int vertex);
};
void Graph::addEdge(int v,int w){
	adjList[v].push_back(w);
}
void Graph::DFS(int vertex){
	stack<int > dfs;
	int v;
	visited[vertex] = true;
	dfs.push(vertex);
	list<int >::reverse_iterator it;
	while(!dfs.empty()){
		v = dfs.top();
		cout<<v<<" ";
		dfs.pop();

		for(it = adjList[v].rbegin(); it != adjList[v].rend(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				dfs.push(*it);
				//cout<<*it<<"is pushed onto stack\n";
				
			}
		}
	}
}



int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
