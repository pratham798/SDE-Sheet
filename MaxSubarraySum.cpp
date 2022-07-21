//Approach 1
//TIme Complexity  O(n2)
//Space Complexity O(1)

long long maxSubarraySum(int arr[], int n)
{
    long long res=INT_MIN;
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum>res) res=sum;
        }
    }
    if(res<0) return 0;
    return res;
    
}

//Approach 2 Kadane's Algorithm 
//TIme Complexity  O(n)
//Space Complexity O(1)
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0,res=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>res) res=sum;
        if(sum<0) sum=0;
    }
    if(res<0) return 0;
    return res;
}