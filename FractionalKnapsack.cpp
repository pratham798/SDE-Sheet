 
// Time Complexity: O(N)+O(NlogN)
// Space Complexity: O(1)
    static bool comp(Item ar1,Item ar2)
    {
        double a=(double)ar1.value/(double)ar1.weight;
        double b=(double)ar2.value/(double)ar2.weight;
        return a>=b;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double val=0.0;
        for(int i=0;i<n;i++)
        {
           if(arr[i].weight<=W)
           {
               val+=arr[i].value;
               W-=arr[i].weight;
           }
           else
           {
               double unit=(double) arr[i].value/ (double) arr[i].weight;
               unit=unit*W;
               val+=unit;
               break;
           }
        }
        return val;
    }