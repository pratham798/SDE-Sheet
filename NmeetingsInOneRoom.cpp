 // Time Complexity: O(2n)+O(NlogN)
// Space Complexity: O(n)
 
 static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>>alot;
        for(int i=0;i<n;i++)
        {
            alot.push_back({start[i],end[i]});
        }
        sort(alot.begin(),alot.end(),comp);
        int count=0,endT=0;
        for(int i=0;i<alot.size();i++)
        {
            if(alot[i][0]<=endT) continue;
            endT=alot[i][1];
            count++;
        }
        return count;
    }