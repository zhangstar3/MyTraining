#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
思路：第一个出现I 就写最小的数，第二个出现I就写倒数第二小的数，
第一个出现D 就写最大的数，第二个出现D就写第二大的数，以此类推。
*/
class Solution {
public:
	static vector<int> diStringMatch(string S) 
	{
		int N=S.length();
		vector<int> v1;
		int n_I=0,n_D=N;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='I')
			{
				v1.push_back(n_I);
				n_I++;
			}
			else
			{
				v1.push_back(n_D);
				n_D--;
			}	
		}
		if(S[N-1]=='I')
			 v1.push_back(n_I);
		else if(S[N-1]=='D')
			v1.push_back(n_D);
		return v1;
	}
};

int main()
{
	int x=4,y=2;
	Solution::diStringMatch("IDID");

	return 0;
}