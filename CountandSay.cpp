 //Time Complexity=O(N)
//Space Complexity=O(1)

string writeAsYouSpeak(int n) 
{
	// Write your code here.
	string res="1";
	for(int i=2;i<=n;i++)
	{
		string check="";
		int count=0;
		for(int i=0;i<res.size();i++)
		{
			if(i>0 and res[i]!=res[i-1]) 
			{
				check=check+to_string(count)+res[i-1];
				count=0;
			}
			count++;
		}
		check=check+to_string(count)+res[res.size()-1];
		res=check;
	}
	return res;	
}