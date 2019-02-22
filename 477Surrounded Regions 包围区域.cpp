class Solution 
{
public:
	int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void solve(vector<vector<char>>& board) 
	{
		if(board.empty()||board[0].empty()) return;
		int M=board.size();
		int N=board[0].size();
		vector<vector<int>> visited(M,vector<int>(N,0));
		for(int i=0;i<M;++i)
		{
			for(int j=0;j<N;++j)
			{
				if((i==0||i==M-1||j==0||j==N-1)&&board[i][j]=='O')
				{
					dfs(board,i,j);
				}
			}
		}
		for(int i=0;i<M;++i)
		{
			for(int j=0;j<N;++j)
			{
				if(board[i][j]=='O')
					board[i][j]='X';
				if(board[i][j]=='$')
					board[i][j]='O';
			}
		}
    }
	void dfs(vector<vector<char>>& board,int i,int j)
	{
		int M=board.size();
		int N=board[0].size();
		if(0<=i&&i<M&&0<=j&&j<N&&board[i][j]=='O')
		{
			board[i][j]='$';
			for(int k=0;k<4;k++)
			{
				int tempX=i+dir[k][0];
				int tempY=j+dir[k][1];
				dfs(board,tempX,tempY);
			}
		}
	}
};