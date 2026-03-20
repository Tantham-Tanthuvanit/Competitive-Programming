#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct connection {
    int vertex;
    int weight;

    connection(int vert, int w) {
        vertex = vert;
        weight = w;
    }
};

struct weightedGraph {
    unordered_map<int, vector<connection>> adj;

    const vector<connection>& getConnections(int v) {
        static vector<connection> empty;
        if (adj.find(v) == adj.end()) return empty;
        return adj[v];
    }

    void addEdge(int u, int v, int w) {
        // Directed Graph: only u -> v
        adj[u].push_back(connection(v, w));
    }
    
    //----------[ BFS ]----------------------//
    void bfs(int startVertex) {
        unordered_set<int> visited;
        queue<int> q;

        visited.insert(startVertex);
        q.push(startVertex);

        bool first = true; // Added to prevent trailing spaces

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // Formatting: only print a space BEFORE the next number, not after
            if (!first) cout << " ";
            cout << current;
            first = false;

            vector<connection> neighbors = getConnections(current);

            sort(neighbors.begin(), neighbors.end(), [](const connection& a, const connection& b) {
                    return a.vertex < b.vertex;
            });

            for (const connection& conn : neighbors) {
                if (visited.find(conn.vertex) == visited.end()) {
                    visited.insert(conn.vertex);
                    q.push(conn.vertex);
                }
            }
        }
        cout << endl;
    }

    //----------------------------[ DFS ]------------------------------------//
    void dfsHelper(int vertex, unordered_set<int>& visited, bool& first) {
        visited.insert(vertex);
        
        // Formatting: only print a space BEFORE the next number
        if (!first) cout << " ";
        cout << vertex;
        first = false;

        vector<connection> neighbors = getConnections(vertex);

        sort(neighbors.begin(), neighbors.end(), 
        [](const connection& a, const connection& b) {
                return a.vertex < b.vertex;
        });

        for (const connection& conn : neighbors) {
            if (visited.find(conn.vertex) == visited.end()) {
                dfsHelper(conn.vertex, visited, first);
            }
        }
    }

    void dfs(int startVertex) {
        unordered_set<int> visited;
        bool first = true; // Passed by reference to the helper to prevent trailing spaces
        dfsHelper(startVertex, visited, first);
        cout << endl;
    }
};

int main() {
    int nvert; 
    if (!(cin >> nvert)) return 0;
    
    weightedGraph graph;

    // 1st loop [ Phase 1: adding edges ]
    while (true) {
        char cmd; 
        cin >> cmd;

        if (cmd == 'e') {
            int start, end, weight;
            cin >> start >> end >> weight;
            graph.addEdge(start, end, weight);
        }
        else if (cmd == 's') {
            break; // Explicitly stop taking edges when 's' is read
        }
        else {
            break; // Safety fallback
        }
    }

    // 2nd loop [ Phase 2: showing values ]
    while (true) {
        char cmd; 
        if (!(cin >> cmd)) break; // Safety fallback in case the file just ends

        if (cmd == 'd') {
            int vert; cin >> vert;
            graph.dfs(vert);
        }
        else if (cmd == 'b') {
            int vert; cin >> vert;
            graph.bfs(vert);
        }
        else if (cmd == 'q') {
            break; // Explicitly quit the program when 'q' is read
        }
        else {
            break; // Safety fallback
        }
    }
    
    return 0;
}
