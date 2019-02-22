class Solution 
{
public:
	int[4][2]dir ={ {1,0},{0,1},{-1,0},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) 
	{
        int M=grid.size();
		int N=grid[0].size();
		int num=0;
		int Maxarea=0;
		vector<vector<int>> visited(M,vector<int>(N,0));
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(grid[i][j]==1&&visited[i][j]==0)
				{
					num=0;
					dfs(grid,i,j,visited,num);
					Maxarea=max(num,Maxarea);
				}
			}
		}
		return Maxarea;
    }
	void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &visited,int &num)
	{
		int M=grid.size();
		int N=grid[0].size();
		if(i<0||i>=M||j<0||j>=N||visited[i][j]==1||grid[i][j]!=1) 
			return;
		visited[i][j]=1;
		num++;    //在此处++
		for(int k=0;k<4;k++)
		{
			int tempX=i+dir[k][0];
			int tempY=j+dir[k][1];
			dfs(grid,tempX,tempY,visited,num);
		}
	}
};