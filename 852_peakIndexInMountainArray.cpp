
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//直接取巧算的最大值下标
class Solution 
{
public:
	int peakIndexInMountainArray(vector<int>& A) 
	{
		int n_max=0,j=0;;
		for(int i=0;i<A.size();i++)
		{
			if(A[i]>n_max)
			{
				n_max=A[i];
				j=i;
			}
		}
		return j;
	}
};