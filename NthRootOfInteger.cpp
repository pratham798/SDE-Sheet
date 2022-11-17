//Time Complexity:- O(log(m*10^d));
//Space Complexity:-O(1)
double findNthRootOfM(int n, int m) {
	// Write your code here.
    double start=1,end=m,mid=0;
    while((end-start)>(1e-7))
    {
       mid=(start+end)/2;
       double res=pow(mid,n);
       if(res>m) end=mid;
       else start=mid;
    }
    return mid;
}