//Approach 1
// Time Complexity: O(nlogn)+o(n)
// Space Complexity: O(n)

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    set<int>s;
    int count=0;
    for(int &i:arr) s.insert(i);
    for(auto&it:s) count++;
    return count;
}

//Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            count--;
        }
        count++;
    }
    return count;
}