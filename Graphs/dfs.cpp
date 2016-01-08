#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int s) {
	stack<int> S;
	int e;
	S.push(s);
	visited[s] = true;
	while(!S.empty()) {
		e = S.top();
		S.pop();
		visited[e] = true;
		cout << e << endl;
		for(int i=1; i < adj[e].size(); i++) {
			if(visited[adj[e][i]]==false) {
				S.push(adj[e][i]);
				visited[adj[e][i]] = true;
			}
		}
	}
}

void initialize() {
	for(int i=0; i < 10; i++) {
		visited[i] = false;
	}
}

int main() {
	int nodes, edges, x, y;
	cin >> nodes;
	cin >> edges;
	for(int i=0; i < edges; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	initialize();
	for(int i=0; i < nodes; i++) {
		if(visited[i] == false) {
			dfs(i);
		}
	}
	return 0;
}
