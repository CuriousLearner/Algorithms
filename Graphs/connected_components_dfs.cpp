// Finding connected components using dfs

/*
Input type:
6				// Nodes
4				// Edges
1 2
2 3
1 3
4 5 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10];
bool visited[10];

void dfs(int s) {
	visited[s] = true;
	for(int i=0; i < v[s].size(); i++) {
		if(visited[v[s][i]] == false) {
			dfs(v[s][i]);
		}
	}

}

void initialize() {
	for(int i=0; i < 10; i++) {
		visited[i] = false;
	}
}

int main() {
	int nodes, edges, x, y, connectedComponents=0;
	cin >> nodes;
	cin >> edges;
	for(int i=0; i < edges; i++) {
		cin >> x >> y;
		// For un-directed graph
		v[x].push_back(y);
		v[y].push_back(x);
	}
	initialize();
	for(int i=0; i < nodes; i++) {
		if(visited[i] == false) {
			dfs(i);
			connectedComponents++;
		}
	}
	cout << "No of connected components in the graph are: " << connectedComponents << endl;
	return 0;
}
