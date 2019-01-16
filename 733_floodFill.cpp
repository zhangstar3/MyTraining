class Solution {
public:
	void dfs(vector<vector<int>>& image,int i,int j,int color,int newColor)
	{
		int m=image.size();
		int n=image[0].size();
		if(i<0||i>=m||j<0||j>=n||image[i][j]!=color)return;
		image[i][j]=newColor;
		dfs(image,i+1,j,color,newColor);
		dfs(image,i,j+1,color,newColor);
		dfs(image,i-1,j,color,newColor);
		dfs(image,i,j-1,color,newColor);
	}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
	{
		if(image[sr][sc]==newColor) return image;
		dfs(image,sr,sc,image[sr][sc],newColor);
		return image;
    }
};

class Solution
{
  public:
	vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int newColor)
	{
		if(image[sr][sc]==newColor) return image;
		int color=image[sr][sc];
		image[sr][sc]=newColor;
		if(sr-1>=0&&image[sr-1][sc]==color)floodFill(image,sr-1,sc,newColor);
		if(sc-1>=0&&image[sr][sc-1]==color)floodFill(image,sr,sc-1,newColor);
		if(sr+1<image.size()&&image[sr+1][sc]==color) floodFill(image,sr+1,sc,newColor);
		if(sc+1<image[0].size()&&image[sr][sc+1]==color)floodFill(image,sr,sc+1,newColor);
		return image;
	}
}

class Solution
{
  public:
vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int newColor)
{
   queue<pair<int,int>> site;
   int color=image[sr][sc];
   image[sr][sc]=newColor;
   site.push(pair<int,int>(sr,sc));
   while(!site.empty())
   {
	 int x=site.front().first;
	 int y=site.front().second;
	 site.pop();
	 if(x-1>=0&&image[x-1][y]==color&&image[x-1][y]!=newColor)
	 {
		 site.push(pair<int,int>(x-1,y));
		 image[x-1][y]=newColor;
	 }
	 if(x+1<image.size()&&image[x+1][y]==color&&image[x+1][y]!=newColor)
	 {
		 site.push(pair<int,int>(x+1,y));
		 image[x+1][y]=newColor;
	 }
	 if(y-1>=0&&image[x][y-1]==color&&image[x][y-1]!=newColor)
	 {
		 site.push(pair<int,int>(x,y-1));
		 image[x][y-1]=newColor;
	 }
	 if(y+1<image[0].size()&&image[x][y+1]==color&&image[x][y+1]!=newColor)
	 {
		site.push(pair<int,int>(x,y+1));
		image[x][y+1]=newColor;
	 }
   }
  return image;
}
};



