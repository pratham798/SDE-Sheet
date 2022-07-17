#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>>res(n,vector<long long int>(n));
    res[0][0]=1;
    res[0].resize(1);
    for(int i=1;i<n;i++)
    {
        res[i].resize(i+1);
        res[i][0]=1;
         for(int j=1;j<=i-1;j++) res[i][j]=res[i-1][j]+res[i-1][j-1];
        res[i][i]=1;
    }
    return res;
    
}