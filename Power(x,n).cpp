// Approach 1
// Time Complexity: O(logn)
// Space Complexity: O(1)

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long long res=1;
    long long ans=x;
    while(n)
    {
        if(n%2!=0)
        {
            res*=ans;
            res%=m;
            n=n-1;
        }
        else
        {
            ans=ans*ans;
            ans%=m;
            n=n/2;
        }
    }
    return res%m;
}
