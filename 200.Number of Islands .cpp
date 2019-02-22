class Solution {
public:
	int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) 
	{
		if(grid.empty()||grid[0].empty()) return 0;
		int M=grid.size();
		int N=grid[0].size(); 
		int num=0;
		vector<vector<int>> visited(M,vector<int>(N,0));
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(visited[i][j]==0&&grid[i][j]=='1')
				{
					dfs(grid,i,j,visited);
                    num++;
				}
			}
		}
		return num;
    }
	void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited)
	{
		int M=grid.size();
		int N=grid[0].size();
		if(0<=i&&i<M&&0<=j&&j<N&&visited[i][j]==0&&grid[i][j]=='1')
		{
			visited[i][j]=1;
			for(int k=0;k<4;k++)
			{
				int tempX=i+dir[k][0];
				int tempY=j+dir[k][1];
				dfs(grid,tempX,tempY,visited);
            }
		}
        
	}
};