// Approach 1

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    next_permutation(permutation.begin(),permutation.end());
    return permutation;
}

//Approach 2
// TIME COMPLEXITY= 3*O(n)
// SPACE COMPLEXITY= O(1)
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int size=permutation.size();
    int ind1=-1,ind2=-1;
    for(int i=size-2;i>=0;i--)
    {
       if(permutation[i]<permutation[i+1]) 
       {
           ind1=i;
           break;
       }
    }
    if(ind1<0) reverse(permutation.begin(),permutation.end());
    else
    {
        for(int i=size-1;i>ind1;i--)
        {
            if(permutation[i]>permutation[ind1]) 
            {
                ind2=i;
                break;
            }
        }
        swap(permutation[ind1],permutation[ind2]);
        reverse(permutation.begin()+ind1+1,permutation.end());
    }
    return permutation;
}