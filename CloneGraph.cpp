//Time Complexity: O(Vertices*Edges)
//Space Complextiy: O(1)

void dfs(Node*curr,Node*copy,vector<Node*>&visited)
    {
        for(auto&it:curr->neighbors)
        {
            if(visited[it->val]==NULL)
            {
                Node*nn=new Node(it->val);
                visited[nn->val]=nn;
                copy->neighbors.push_back(nn);
                dfs(it,nn,visited);
            }
            else copy->neighbors.push_back(visited[it->val]);
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL) return node;
        vector<Node*>visited(1000,NULL);
        Node*copy=new Node(node->val);
        visited[node->val]=copy;
        for(auto&it:node->neighbors)
        {
            if(visited[it->val]==NULL)
            {
                Node*nn=new Node(it->val);
                copy->neighbors.push_back(nn);
                visited[nn->val]=nn;
                dfs(it,nn,visited);
            }
            else copy->neighbors.push_back(visited[it->val]);
        }
        return copy;
    }