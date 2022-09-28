#include<cstdio>

#define MAXN 10000
using namespace std;
template <class T>
class bqueue{
	public:
		T data[MAXN];
		int rear0,rear1;
		bqueue()
		{
			this->rear0=0;
			this->rear1=MAXN-1;
		}
		void push(int i,T x)
		{
			if(rear0>rear1)
			{
				printf("栈已经满了!\n");
				return;
			}
			if(i==0)
			{
				data[rear0]=x;
				rear0++;
				return;
			}
			if(i==1)
			{
				data[rear1]=x;
				rear1--;
				return;
			}
		}
		
		bool pop(int i)
		{
			if(i==0)
			{
				if(rear0<=0)
				{
					return false;
				}
				rear0--;
				return true;
			}
			if(i==1)
			{
				if(rear1>=MAXN-1)
				{
					return false;
				}
				rear1++;
				return true;
			}
		}
		
		T top(int i)
		{
			T a;
			if(i==0)
			{
				if(rear0<=0)
				{
					return a;
				}
				return data[rear0-1];
			}
			if(i==1)
			{
				if(rear1>=MAXN-1)
				{
					return a;
				}
				return data[rear1+1];
			}
		}
};

int main()
{
	int n,temp;
	bqueue<int> q;
	printf("请输入整数，输入EOF结束\n");
	while(scanf("%d",&n))
	{
		if(n%2)q.push(0,n);
		else q.push(1,n);
	}
	while(1){
		int temp=q.top(0);
		if(q.pop(0))printf("%d ",temp);
		else break;
	}
	printf("\n");
	while(1){
		int temp=q.top(1);
		if(q.pop(1))printf("%d ",temp);
		else break;
	}
} 
