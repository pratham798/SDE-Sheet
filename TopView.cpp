//Time Complexity=O(N)
//Space Complexity=O(2N)

vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            Node*curr=q.front().first;
            int ind=q.front().second;
            q.pop();
            if(m.find(ind)==m.end()) m[ind]=curr->data;
            if(curr->left) q.push({curr->left,ind-1});
            if(curr->right) q.push({curr->right,ind+1});
        }
        vector<int>res;
        for(auto&it:m) res.push_back(it.second);
        return res;
    }
