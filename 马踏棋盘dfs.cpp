#include<stdio.h>
#include<string.h>
#define MAXN 6

int vis[MAXN+4][MAXN+4]={0};
int step_x[MAXN*MAXN]={0},step_y[MAXN*MAXN]={0};
int max_step_x[MAXN*MAXN]={0},max_step_y[MAXN*MAXN]={0};
int max_step=0;
void dfs(int x,int y,int step)
{
	if(vis[x+2][y+2]!=0)
	{
		if(step>max_step)
		{
			for(int i=0;i<MAXN*MAXN;i++)
			{
				max_step_x[i]=step_x[i];
				max_step_y[i]=step_y[i];
			}
			max_step=step;
		}
		return;
	}
	vis[x+2][y+2]=1;
	step_x[step]=x;
	step_y[step]=y;
	step+=1;
	dfs(x-1,y+2,step);
	dfs(x-2,y+1,step);
	dfs(x-2,y-1,step);
	dfs(x-1,y-2,step);
	dfs(x+1,y+2,step);
	dfs(x+2,y+1,step);
	dfs(x+1,y-2,step);
	dfs(x+2,y-1,step);
	step_x[step]=-1;
	step_y[step]=-1;
	step-=1;
	vis[x+2][y+2]=0;
}

int main()
{
	memset(step_x,-1,sizeof(step_x));
	memset(step_y,-1,sizeof(step_y));
	memset(max_step_x,-1,sizeof(max_step_x));
	memset(max_step_y,-1,sizeof(max_step_y));
	for(int i=0;i<MAXN+4;i++)
	{
		vis[0][i]=1;
		vis[1][i]=1;
		vis[MAXN+2][i]=1;
		vis[MAXN+3][i]=1;
		vis[i][0]=1;
		vis[i][1]=1;
		vis[i][MAXN+2]=1;
		vis[i][MAXN+3]=1;
	}
	dfs(3,4,0);
	printf("最长路径为:%d步,路线为:\n",max_step);
	for(int i=0;max_step_x[i]>=0;i++)
	{
		printf("%d %d\n",max_step_x[i],max_step_y[i]);
	}
}

