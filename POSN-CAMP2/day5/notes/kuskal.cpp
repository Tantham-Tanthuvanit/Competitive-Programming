#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

struct edge {
	int srcVertex;
	int endVertex;
	int weight;
	edge(int sv, int ev, int w) : srcVertex(sv), endVertex(ev), weight(w) {}
};

struct graph {
	int nvertecies;
	int nedges;
	vector<edge> edges;

	void addEdge(int start, int end, int weight) {
		edges.push_back(edge(start, end, weight));

		nedges++;
	}
};

int main() {

	return 0;

}
