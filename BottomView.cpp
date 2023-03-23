//Time Complexity=O(N)
//Space Complexity=O(N)
   
   vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            Node*curr=q.front().first;
            int ind=q.front().second;
            q.pop();
            m[ind]=curr->data;
            if(curr->left) q.push({curr->left,ind-1});
            if(curr->right) q.push({curr->right,ind+1});
        }
        vector<int>res;
        for(auto&it:m) res.push_back(it.second);
        return res;
    }