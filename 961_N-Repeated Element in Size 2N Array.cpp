class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    
    {
        vector<int> v1,v2;
		for(vector<int>::iterator it=A.begin();it!=A.end();it++)
		{
			if(*it%2==0)
				v1.push_back(*it);
			else
				v2.push_back(*it);
		}
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
		{
			v1.push_back(*it);
		}        
		return v1;
    }
};