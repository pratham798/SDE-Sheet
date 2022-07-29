// Approach 1
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

int findMajorityElement(int arr[], int n) {
	// Write your code here.
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
        if(m[arr[i]]>n/2) return arr[i];
    }
    return -1;
}


// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int ele=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(count==0) ele=arr[i];
        if(arr[i]==ele) count+=1;
        else if(arr[i]!=ele) count-=1;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele) count++;
    }
    if(count>n/2) return ele;
    return -1;
}