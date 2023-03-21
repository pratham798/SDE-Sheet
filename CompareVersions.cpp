//Time Complexity=O(N)
//Space Complexity=O(1)

int compareVersion(string a, string b) 
    {
        int n1=0,n2=0,len1=a.size(),len2=b.size(),i=0,j=0;
        while(i<len1 || j<len2)
        {
            n1=0,n2=0;
            while(i<len1 and a[i]!='.')
            {
                n1=n1*10+(a[i]-'0');
                i++;
            }
            while(j<len2 and b[j]!='.')
            {
                n2=n2*10+(b[j]-'0');
                j++;
            }
            if(n1>n2) return 1;
            if(n2>n1) return -1;
            i++;
            j++;
        }
        return 0;
    }