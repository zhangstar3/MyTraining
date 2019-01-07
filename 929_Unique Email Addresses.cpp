#include "vector"
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution 
{
public:
	static int numUniqueEmails(vector<string>& emails)
	{
		set<string> res;
		int size=emails.size();
		if(size==0) return 0;
		int index;
		for(int i=0;i<size;i++)//test.emai+l@leetcode.com
		{
			string temp=emails[i];
			index=temp.find('@');
			temp=temp.substr(0,index);
			int hasAdd=temp.find('+');
			//emails[i]=emails[i].erase(hasAdd,5);
			if (hasAdd==-1)
				temp=temp.substr(hasAdd+1,index-hasAdd);
			else
				temp=temp.substr(0,hasAdd);//+temp.substr(hasAdd+1,index-hasAdd);
			int hasdot=temp.find('.');
			while(hasdot!=-1)
			{
				temp=temp.substr(0,hasdot)+temp.substr(hasdot+1,-1);
				hasdot=temp.find('.');
			}
			temp=temp+emails[i].substr(index,-1);
			emails[i]=temp;
		}          
		for(int i=0;i<size;i++)
			res.insert(emails[i]);
		return res.size();
	}
};

void main()
{
	//char* buf="t+estemail@leetcode.com";
	//emails[i]=emails[i].substr(0,hasAdd)+emails[i].substr(hasAdd,index-hasAdd);
	vector<string> v1;
	
	v1.push_back("test.e.mail+bob.cathy@leetcode.com");
	v1.push_back("tes+temail@leetcode.com");
	v1.push_back("testemail+david@lee.tcode.com");
	int num=Solution::numUniqueEmails(v1);

	return;
}