//Time Complexity: O(n+m)
//Space Complexity: O(1)        
        
        
        int n1=a.size(),n2=b.size();
        if(n2<n1) return findMedianSortedArrays(b,a);
        int low=0,high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;
            int l1=cut1==0?INT_MIN:a[cut1-1];
            int l2=cut2==0?INT_MIN:b[cut2-1];
            int r1=cut1==n1?INT_MAX:a[cut1];
            int r2=cut2==n2?INT_MAX:b[cut2];

            if(l1<=r2 and l2<=r1)
            {
                if((n1+n2)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                return max(l1,l2);
            }
            else if(l1>r2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.0;