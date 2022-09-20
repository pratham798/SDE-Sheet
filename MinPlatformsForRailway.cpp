   
//Approach 1
// Time Complexity: O(n^2)+O(2nlogn)
// Space Complexity: O(1)

   int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans=1;
    	for(int i=0;i<n;i++)
    	{
    	    int count=1;
    	    for(int j=i+1;j<n;j++)
    	    {
    	        if((arr[i]>=arr[j] and arr[i]<=dep[j])||(arr[i]<=arr[j] and dep[i]>=arr[j]))
    	        {
    	            count++;
    	        }
    	    }
    	    ans=max(ans,count);
    	}
    	return ans;
    }

//Approach 2
// Time Complexity: O(n)+O(2nlogn)
// Space Complexity: O(1)

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int ans=0,i=0,j=0,count=0;
    while(i<n and j<n)
    {
        if(at[i]<=dt[j])
        {
            count++;
            i++;
        }
        else
        {
           j++;
           count--;
        }
        ans=max(count,ans);
    }
    return ans;
}