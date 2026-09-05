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
unordered_map<Node*,Node*> mpp;
void dfs(Node* node){
    Node* copy = new Node(node->val);
    mpp[node] = copy;
    for(auto ng : node->neighbors){
        if(mpp.find(ng) != mpp.end())
        copy->neighbors.push_back(mpp[ng]);
        else{
            dfs(ng);
            copy->neighbors.push_back(mpp[ng]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        dfs(node);
        return mpp[node];
    }
};
