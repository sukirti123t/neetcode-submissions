/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> oldToNew;

    Node* cloneGraph(Node* node) {

        // Base case: empty graph
        if (node == NULL) {
            return NULL;
        }

        // If already cloned, return the cloned node
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a copy of the current node
        Node* copy = new Node(node->val);

        // Store the mapping
        oldToNew[node] = copy;

        // Clone all neighbors
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};