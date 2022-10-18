class Solution {
public:
    unordered_map<Node*, Node*> clone;
    Node* cloneGraph(Node* node) {
        //DFS
        if(!node) return NULL;
        if(!clone.count(node)){
            clone[node] = new Node(node->val);
            for(auto it:node->neighbors){
                clone[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return clone[node];
        /* //BFS
        if(!node) return NULL;
        queue<Node*> q;
        clone[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto it:curr->neighbors){
                if(!clone.count(it)){
                    clone[it] = new Node(it->val);
                    q.push(it);
                }
                clone[curr]->neighbors.push_back(clone[it]);
            }
        }

        return clone[node]; */
    }
