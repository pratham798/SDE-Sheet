// Approach 1
// Time Complexity O(N*Nlog N)
// Space Complexity O(1)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    for(int i=0;i<m;i++)
    {
        if(arr1[i]>0 and arr1[i]>arr2[0]) 
        {
            swap(arr1[i],arr2[0]);
            sort(arr2.begin(),arr2.end()); //or use insertion sort TC improved to O(N*M)
        }
    }
    for(int i=0;i<n;i++)
    {
        arr1[m+i]=arr2[i];
    }
    return arr1;
}

// Approach 2(using gap method)
// Time Complexity O(logN)
// Space Complexity O(1)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int size=m+n;
    int gap=ceil((float)(size)/2);
    while(gap>0)
    {
        int i=0,j=gap;
        while(j<(m+n))
        {
            if(j<m and arr1[i]>arr1[j]) swap(arr1[i],arr1[j]);
            else if(j>=m and i<m and arr1[i]>arr2[j-m] ) swap(arr1[i],arr2[j-m]);
            else if(i>=m and j>=m and arr2[i-m]>arr2[j-m] ) swap(arr2[i-m],arr2[j-m]);
            i++;
            j++;
        }
        if(gap==1) gap=0;
        else gap=ceil((float)(gap)/2);
    }
    int j=0;
    for(int i=m;i<m+n;i++)
    {
        arr1[i]=arr2[j++];
    }
    return arr1;
}

