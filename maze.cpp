#include<cstdio>
#include<queue>
#define MAXN 4
using namespace std;
int maze[MAXN+2][MAXN+2]={0};
int vis[MAXN+2][MAXN+2]={0};
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

struct point{
	int x;
	int y;
	int step;
};
queue<point> point_q;
bool find_next(point *p)
{
	point a;
	if(p->x==MAXN&&p->y==MAXN)return true;
	a.step=p->step+1;
	for(int i=0;i<4;i++)
	{
		a.x=p->x+dx[i];
		a.y=p->y+dy[i];
		if(vis[a.x][a.y]==0&&maze[a.x][a.y]==0)
		{
			point_q.push(a);
			vis[a.x][a.y]=a.step;
		}
		
	}	
	return false;
}

void print_route(point *p)
{
	point a;
	for(int i=0;i<4;i++)
	{
		a.x=p->x+dx[i];
		a.y=p->y+dy[i];
		if(vis[a.x][a.y]==vis[p->x][p->y]-1)
		{
			print_route(&a);
			printf("%d %d\n",p->x,p->y);
			return;
		}
	}
}

int main()
{
	for(int i=0;i<MAXN+2;i++)
	{
		maze[0][i]=1;
		maze[i][0]=1;
		maze[i][MAXN+1]=1;
		maze[MAXN+1][i]=1;
	}
	int x,y;
	while(scanf("%d%d",&x,&y)==2)
	{
		maze[x][y]=1;
	}
	point start;
	start.x=1;
	start.y=1;
	start.step=1;
	point_q.push(start);
	vis[1][1]=1;
	while(!find_next(&(point_q.front())))
	{
		point_q.pop();
		if(point_q.empty()){
			printf("can't find a route!");
			return 0;
		}
	}
	point end;
	end.x=MAXN;
	end.y=MAXN;
	end.step=vis[MAXN][MAXN];
	print_route(&end);
}
