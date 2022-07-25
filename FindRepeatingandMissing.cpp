// Approach 1
// Time Complexity O(N)
// Space Complexiity O(N)
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    unordered_map<int,int>m;
    int a=0,b=0;
    for(auto &i:arr) m[i]++;
	for(int i=1;i<=n;i++)
    {
        if(m[i]==0) a=i;
        else if(m[i]==2) b=i;
        else if(a and b) break;
    }
    return {a,b};
}
// Approach 2(using XOR)
// Time Complexity O(N)
// Space Complexiity O(1)

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int xor1;

    
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
    set_bit_no = xor1 & ~(xor1 - 1);


    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];

        else
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            x = x ^ i;

        else
            y = y ^ i;
    }
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}