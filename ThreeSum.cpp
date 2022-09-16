//Approach 1
// Time Complexity: O(n^2)+O(nlogn)
// Space Complexity: O(3*k)

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    if(arr.size()<3) return res;
    for(int i=0;i<n-2;i++)
    {
        int low=i+1;
        int high=n-1;
        while(low<high)
        {
            if(arr[i]+arr[low]+arr[high]==K)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[low]);
                temp.push_back(arr[high]);
                res.push_back(temp);
                while(low<high and arr[low]==arr[low+1]) low++;
                while(low<high and arr[high]==arr[high-1]) high--;
                low++;
                high--;
            }
            else if(arr[i]+arr[low]+arr[high]<K) low++;
            else high--;
        }
        while(i<n-2 and arr[i]==arr[i+1]) i++;
    }
    return res;
}