class Solution 
{
public:
	vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) 
	{
		if(grid.size()=0||grid[0].size()==0)
			return 0;
		int maxx=0;
		int M=grid.size();
		int N=grid[0].size();
		
		vector<vector<int>> visited(M,vector<int>(N,0));
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				int area=0;
				if(visited[i][j]==0&&grid[i][j]==1)
				{
					dfs(grid,visited,i,j,area);
					maxx=max(maxx,area);
				}
			}
		}
		return maxx;
    }
	void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int &area)
	{
		if(0<=i&&i<grid.size()&&0<=j&&j<grid[0].size()&&visited[i][j]==0&&grid[i][j]==1)
		{
			area++;
			visited[i][j]=1;
			for(int k=0;k<4;k++)
			{
				int tempX=x+dir[k][0];
				int tempY=y+dir[k][1];
				dfs(grid,visited,tempX,tempY,area);
			}
		}
	}
};