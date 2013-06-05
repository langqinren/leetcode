/*
 * two methods: BSF & DSF
 * two graphs:  directed & undirected
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
	vector<Node*> neighbors;
};


Node* cloneGraph(Node* graph) {
	unordered_map<Node*, Node*> nodeM;
	unordered_set<Node*>        nodeS;
	queue<Node*>                nodeQ;
	nodeQ.push(graph);
	
	Node *copy, *node, *ngraph;
	ngraph = copy = new Node();
	nodeM[graph] = copy;

	while (!nodeQ.empty()) {
		node = nodeQ.front();
		copy = nodeM[node];
		nodeQ.pop();

		nodeS.insert(node);
		for (int i=0; i<node->neighbors.size(); i++) {
			Node* neig  = node->neighbors[i];
			Node* cneig = new Node();
			copy->neighbors.push_back(cneig);
		}		
	}

	return ngraph;
}
