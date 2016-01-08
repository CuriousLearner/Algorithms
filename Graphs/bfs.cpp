#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10];
bool visited[10];

void bfs(int s) {
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		cout << p << endl;
		for(int i=0; i < adj[p].size(); i++) {
			if(visited[adj[p][i]] == false) {
				q.push(adj[p][i]);
				visited[adj[p][i]] = true;
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
	bfs(0);
	return 0;
}
