// Approach 1
// Time Complexity 2*O(n)
// Space Complexiity O(1)
void sort012(int *arr, int n)
{
   //   Write your code here
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) c0++;
        if(arr[i]==1) c1++;
        else c2++;
    }
    for(int i=0;i<n;i++)
    {
        if(c0-->0) arr[i]=0;
        else if(c1-->0) arr[i]=1;
        else arr[i]=2;
    }
}
//Approach 2 STL
// Time Complexity   O(n)
// Space Complexiity O(1)
   sort(arr,arr+n);
//Approach 3 (3 pointer- Dutch National Flag ALgorithm)
// Time Complexity   O(n)
// Space Complexiity O(1)
void sort012(int *arr, int n)
{
   //   Write your code here
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
       if(arr[mid]==0)
       {
           swap(arr[mid],arr[low]);
           low++;
           mid++;
       }
       else if(arr[mid]==1) mid++;
       else if(arr[mid]==2)
       {
           swap(arr[mid],arr[high]);
           high--;
       }
   }
}

