#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    if (!(cin >> n)) return 0;
    
    // Read the zone for each station
    vector<int> zones(n);
    for (int i = 0; i < n; i++) {
        cin >> zones[i];
    }

    // Adjacency list for the metro connections
    vector<vector<int>> adj(n);
    char cmd;

    // Phase 1: Read the edges until 's'
    while (cin >> cmd) {
        if (cmd == 's') {
            break;
        } else if (cmd == 'e') {
            int u, v;
            cin >> u >> v;
            // Metro lines go both ways (Undirected Graph)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Phase 2: Process the travel queries until 'q'
    while (cin >> cmd) {
        if (cmd == 'q') {
            break;
        } else if (cmd == 'b' || cmd == 'd') {
            int start, target;
            cin >> start >> target;

            // --- STEP 1: Unconstrained BFS (Find shortest physical distance) ---
            int min_stops = -1;
            vector<int> dist(n, -1);
            queue<int> q;
            
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (curr == target) {
                    min_stops = dist[curr];
                    break;
                }

                for (int neighbor : adj[curr]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }

            // --- STEP 2: Constrained BFS (Check ticket validity) ---
            bool canTravel = false;
            
            // Helper function to check if a zone is valid for the current ticket
            auto isZoneValid = [&](int z) {
                if (cmd == 'b') {
                    return z == 1 || z == 2; // Normal ticket: Zones 1 and 2 only
                }
                return true; // Special ticket ('d'): All zones
            };

            // Only search if a physical path exists AND our start/end stations are allowed
            if (min_stops != -1 && isZoneValid(zones[start]) && isZoneValid(zones[target])) {
                vector<bool> visited(n, false);
                queue<int> valid_q;
                
                valid_q.push(start);
                visited[start] = true;

                while (!valid_q.empty()) {
                    int curr = valid_q.front();
                    valid_q.pop();

                    if (curr == target) {
                        canTravel = true;
                        break;
                    }

                    for (int neighbor : adj[curr]) {
                        // Only travel to the neighbor if it hasn't been visited AND its zone is valid
                        if (!visited[neighbor] && isZoneValid(zones[neighbor])) {
                            visited[neighbor] = true;
                            valid_q.push(neighbor);
                        }
                    }
                }
            }

            // --- STEP 3: Print Output ---
            if (min_stops == -1) {
                // No physical path exists at all
                cout << "0 N\n";
            } else {
                cout << min_stops << " " << (canTravel ? "Y" : "N") << "\n";
            }
        }
    }

    return 0;
}
