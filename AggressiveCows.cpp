// Time Complexity: O(NlogN)+O(NlogM)=>O(NlogM)
// Space Complexity: O(1)
#include <bits/stdc++.h> 
bool isPossible(vector<int>&positions,int gap,int c)
{
	int count=1,prev=0;
	for(int i=1;i<positions.size();i++)
	{
		if(abs(positions[i]-positions[prev])>=gap)
		{
			count++;
			prev=i;
		}
		if(count==c) return true;
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int start=0,end=positions[n-1],res=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(isPossible(positions,mid,c))
		{
			res=mid;
			start=mid+1;
		}
		else end=mid-1;
	}
	return res;
}
//