//Implement depth first search algorithm and Breadth First Search algorithm, Use an
// undirected graph and develop a recursive algorithm for searching all the vertices of a
// graph or tree data structure
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<bool> visit;

void edge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// BFS
void bfs(int s, vector<int> adj[]) {
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visit[adj[u][i]]) {
                q.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}

// DFS
void dfs(int s, vector<int> adj[]) {
    stack<int> stk;
    stk.push(s);
    visit[s] = true;
    while (!stk.empty()) {
        int u = stk.top();
        cout << u << " ";
        stk.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visit[adj[u][i]]) {
                stk.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}

int main() {
    int n, e;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    visit.assign(n, false);
    vector<int> adj[n];

    int u, v;

    cout << "Enter the edges with source and destination: \n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            edge(adj, u, v);
        } else {
            cout << "Invalid edge. Vertex indices should be between 0 and " << n - 1 << endl;
            i--; // Re-enter the edge
        }
    }

    cout << "BFS of the given graph is: ";
    bfs(0, adj);
    cout << endl;

    cout << "DFS of the given graph is: ";
    visit.assign(n, false);
    dfs(0, adj);
    cout << endl;

    return 0;
}
//Enter the number of vertices: 5
//Enter the number of edges: 6
//Enter the edges with source and destination:
//0 1
//0 2
//1 3
//2 0
//2 3
//2 4
//BFS of the given graph is: 0 1 2 3 4
//DFS of the given graph is: 0 2 4 3 1

