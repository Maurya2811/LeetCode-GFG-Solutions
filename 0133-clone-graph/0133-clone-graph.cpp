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

unordered_map<Node*,Node*> mp;
void DFS(Node* node, Node* clone_node){
    for(Node* n: node->neighbors){
        if(mp.find(n)==mp.end()){
            Node* clone= new Node(n->val);
            mp[n]=clone;
            clone_node->neighbors.push_back(clone);
            DFS(n,clone);
        }
        else{
            clone_node->neighbors.push_back(mp[n]);
        }
    }
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // for Null Graph
        if(!node)
            return NULL;
        // Clone the given node
        Node* clone_node = new Node(node->val);
        // Now , Clone its neighbors and recursively their neighbors
        /*
          But if a node reappears, then we need to access that cloned node
          So, store them in a map < Node* , Node*>
        */
        mp[node]=clone_node;
        
        DFS(node,clone_node);
        
        return clone_node;
    }
};