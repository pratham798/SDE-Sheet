// Approach 1
// Time Complexity O(nlogn+n)
// Space Complexiity O(1)
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==arr[i+1]) return arr[i];
    }
        return -1;
}
// Approach 2
// Time Complexity O(n)
// Space Complexiity O(n)
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    vector<int>freq(arr.size()+1,0);
    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]+=1;
        if(freq[arr[i]]==2) return arr[i];
    }
        return -1;
}
// Best Approach (Cycle Method)
// Time Complexity O(n)
// Space Complexiity O(1) 
int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
    int slow=nums[0],fast=nums[0];
    do
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    while(slow!=fast);
    fast=nums[0];
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
