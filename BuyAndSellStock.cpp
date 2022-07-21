// Approach 1
// Time Complexity O(n2)
// Space Complexiity O(1)

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int res=0;
    int n=prices.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res=max(res,prices[j]-prices[i]);
        }
    }
    return res;
}

// Approach 2
// Time Complexity O(n)
// Space Complexiity O(1)

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit=0,mini=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        int diff=prices[i]-mini;
        profit=max(profit,diff);
        mini=min(mini,prices[i]);
    }
    return profit;
}