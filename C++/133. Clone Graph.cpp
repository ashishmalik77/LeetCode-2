/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*>created;
    unordered_map<int, int>visited;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* root= new UndirectedGraphNode(node->label);
        created[node->label] = root;
        DFS(root, node);
        return root;
    }
    
    void DFS(UndirectedGraphNode* root, UndirectedGraphNode* node){
        for(auto x: node->neighbors){
            UndirectedGraphNode* copy;
            if(created.count(x->label)) copy = created[x->label];
            else{
                copy = new UndirectedGraphNode(x->label);
                created[x->label] = copy;
            }
            if(x != node && !visited.count(x->label)) DFS(copy, x);
            root->neighbors.push_back(copy);
            visited[x->label]++;
        }
    }
};