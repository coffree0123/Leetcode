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
    Node *root;
    unordered_map<int, Node *> val2node;

    void dfs(Node *node, Node *cur) {
        for (auto v : node -> neighbors) {
            if (!val2node.count(v -> val)) {
                Node *adj = new Node(v -> val);
                val2node[v -> val] = adj;
                cur -> neighbors.push_back(adj);
                dfs(v, cur -> neighbors.back());
            } else {
                cur -> neighbors.push_back(val2node[v -> val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        root = new Node(node -> val);
        val2node[node -> val] = root;
        dfs(node, root);

        return root;
    }
};
