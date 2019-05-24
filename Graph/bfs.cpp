#include <iostream>
#include <list>

using namespace std;
class Graph{
	int V;
	list<int> *adjList;
	bool *visited;//keep track of already visited nodes
public:
	Graph(int V);
	void addEdge(int v,int w);
	void BFS(int s);
};
Graph::Graph(int V){
	int i;
	this->V = V;
	adjList = new list<int >[V];
	visited = new bool[V];
	for(i=0;i<V;i++)
	visited[i] =false;
}
void Graph::addEdge(int v,int w){
	adjList[v].push_back(w);
}
void Graph::BFS(int s){
	list<int > queue;
	visited[s] = true;
	queue.push_back(s);

	list<int >::iterator it;
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		cout<<s<<" ";

		for(it = adjList[s].begin(); it != adjList[s].end();it++){
			if(!visited[*it]){
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}

}
int main(){
	int V,E;
	int a,b;
	int startv;
	cout<<"Input no vertices: ";
	cin>>V;
	cout<<"Input no edges: ";
	cin>>E;

	Graph g(V);
	cout<<"Input edge a b :";
	while(E--){
		cin>>a>>b;
		g.addEdge(a,b);	
	}
	cout<<"Starting vertex:";
	cin>>startv;
	g.BFS(startv);
 
    return 0;
}
