#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#define MAXQUEUE 1000
#define MAXT 50000
#define LAMBDA 3
using namespace std;

int time=0;
int total_wait_time=0;
int client_distribution[MAXT];
float poisson_table[MAXT];

int poisson()
{
	int pos;
	float r;
	r=1.0*rand()/RAND_MAX;
	for(pos=0;r>poisson_table[pos]&&poisson_table[pos];pos++);
	return pos;
}

void init_distribution(int n)
{
	float possibility=0;
	int step=1;
	for(int i=0;i<MAXT;i++)
	{
		possibility+=pow(LAMBDA,i)*exp(-LAMBDA)/step;
		step*=i+1;
		poisson_table[i]=possibility;
		if(possibility>0.9999)break;
	}
	
	for(int i=0;i<n;i++)
	{
		client_distribution[poisson()]++;
	}
	/*for(int i=0;i<MAXT;i++)
	{
		printf("%d ",client_distribution[i]);
		sum+=client_distribution[i];
		//printf("%f\n",poisson_table[i]);
	}
	printf("%d^",sum);*/
}

class client{
	public:
		int arrive_t;
		int serve_t;
		client(){}
		void init_client()
		{
			this->arrive_t=time;
			this->serve_t=rand()%6+5;
		}
		int behavior()
		{
			this->serve_t--;
			if(this->serve_t==0)return 1;
			return 0;
		}
};

class queues{
	public:
		queue<client> all_queue[MAXQUEUE];
		int maxq;
		queues(){}
		void _push()
		{
			client c;
			c.init_client();
			int j;
			int minl=99999999;
			for(int i=0;i<maxq;i++)
			{
				if(all_queue[i].size()<minl)
				{
					j=i;
					minl=all_queue[i].size();
				}
			}
			all_queue[j].push(c);
		}
		bool queue_up()
		{
			bool flag=false;
			for(int i=0;i<maxq;i++)
			{
				if(all_queue[i].empty());
				else{
					total_wait_time+=all_queue[i].size()-1;
					flag=true;
					if(all_queue[i].front().behavior()){
						all_queue[i].pop();
					}
				}
			}
			return flag;
		}
	
}q;

int main()
{
	int m,n;
	client t;
	printf("请输入服务窗口数量和客户数量\n");
	scanf("%d%d",&m,&n);
	init_distribution(n);
	for(int i=0;i<20;i++)printf("%d %f\n",client_distribution[i],poisson_table[i]);
	q.maxq=m;
	do{
		for(int i=0;i<client_distribution[time];i++)
		q._push();
		/*for(int i=0;i<q.maxq;i++)
		{
			//printf("%d ",q.all_queue[i].size());
			if(q.all_queue[i].size())
			{
				t=q.all_queue[i].front();
				printf("%d:%d %d %d\n",i,q.all_queue[i].size(),t.arrive_t,t.serve_t);
			}
			
		}
		printf("&\n");
		*/
		time++;
	}while(q.queue_up());
	printf("平均一个人的等待时间为:%f",1.0*total_wait_time/n);
}

