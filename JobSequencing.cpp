// Time Complexity: O(n*m)+O(nlogn)
// Space Complexity: O(m)

    static bool comp(Job j1,Job j2)
    {
        return j1.profit>j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int slot=0;
        for(int i=0;i<n;i++)
        {
            slot=max(slot,arr[i].dead);
        }
        vector<int>slots(slot+1,-1);
        int count=0,ans=0;
        for(int i=0;i<n;i++)
        {
            int check=arr[i].dead;
            for(int j=check;j>0;j--)
            {
                if(slots[j]==-1)
                {
                    slots[j]=arr[i].id;
                    count++;
                    ans+=arr[i].profit;
                    break;
                }
            }
        }
        return {count,ans};
    } 